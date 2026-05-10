# 42 Lisboa — C++ Modules

A collection of C++ projects developed as part of the 42 Lisboa Common Core curriculum. Each module introduces new Object-Oriented Programming concepts, following the **C++98 standard**.

> **Note:** From Module 02 onwards, all classes follow the Orthodox Canonical Form. The STL (containers and algorithms) is only permitted in Modules 08 and 09.

---

## Modules

| Module | Topics |
|--------|--------|
| [CPP00](#cpp00--namespaces-classes-and-basic-io) | Namespaces, classes, member functions, streams, static, const |
| [CPP01](#cpp01--memory-allocation-references-and-switch) | Memory allocation, heap vs stack, pointers to members, references, switch |
| [CPP02](#cpp02--orthodox-canonical-form-and-operator-overloading) | Orthodox Canonical Form, fixed-point numbers, operator overloading |
| [CPP03](#cpp03--inheritance) | Inheritance, construction/destruction chaining, virtual inheritance, diamond problem |
| [CPP04](#cpp04--subtype-polymorphism-abstract-classes-and-interfaces) | Virtual functions, abstract classes, deep copy, interfaces |
| [CPP05](#cpp05--repetition-and-exceptions) | Exceptions, nested exception classes, abstract forms, intern pattern |
| [CPP06](#cpp06--c-casts) | `static_cast`, `reinterpret_cast`, `dynamic_cast`, type identification |
| [CPP07](#cpp07--c-templates) | Function templates, class templates, `iter`, generic `Array<T>` |
| [CPP08](#cpp08--templated-containers-iterators-algorithms) | STL containers, `std::find`, `std::sort`, `Span`, iterable `MutantStack` |
| [CPP09](#cpp09--stl) | `std::map`, `std::stack`, Ford-Johnson sort with `vector` + `deque` |

---

## CPP00 — Namespaces, Classes and Basic I/O

> First steps in C++: classes, member functions, stdio streams, initialization lists, `static`, and `const`.

### ex00 — Megaphone

A simple command-line program that converts all arguments to uppercase. If no arguments are provided, it outputs a feedback noise.

**Key concepts:** `std::string`, `std::toupper`, command-line arguments.

**Files:** `megaphone.cpp`, `Makefile`

```
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

### ex01 — My Awesome PhoneBook

A terminal phonebook application that stores up to 8 contacts. When a 9th contact is added, it replaces the oldest one (circular buffer). No dynamic allocation.

**Key concepts:** Classes, encapsulation, `static` arrays, `std::iomanip` for formatted output, input validation.

**Files:** `main.cpp`, `PhoneBook.hpp`, `PhoneBook.cpp`, `Contact.hpp`, `Contact.cpp`, `Makefile`

**Classes:**

- **`Contact`** — stores five private fields (`_firstName`, `_lastName`, `_nickName`, `_phoneNumber`, `_darkestSecret`) with full getters and setters.
- **`PhoneBook`** — holds a static array of 8 `Contact` objects, tracks current slot (`_nbr_contacts`) and total added (`_total_contacts`) via a circular index.

**Commands:**

| Command | Behaviour |
|---------|-----------|
| `ADD` | Prompts for all five fields (no empty fields allowed) and saves the contact. |
| `SEARCH` | Displays all contacts in a 10-char-wide, right-aligned, pipe-separated table. Truncates long fields with `'.'`. Allows viewing a full contact by index. |
| `EXIT` | Quits the program. |

**Notable implementation details:**
- Input validation per field type: alpha-only for names/nickname, digits-only for phone number, alphanumeric+spaces for darkest secret.
- ANSI colour codes and ASCII art banners for each menu state.
- `SIGINT` is ignored (`SIG_IGN`) to prevent accidental quit with `Ctrl+C`.
- EOF input (`Ctrl+D`) is handled gracefully with a goodbye screen.

---

## CPP01 — Memory Allocation, References and Switch

> Stack vs heap, `new`/`delete`, references vs pointers, pointers to member functions, file I/O, and `switch`.

### ex00 — BraiiiiiiinnnzzzZ

Introduces the fundamental question of **stack vs heap allocation** through a `Zombie` class that announces itself on construction and prints a death message on destruction.

**Key concepts:** `new`/`delete`, stack vs heap lifetime, constructor/destructor side effects.

**Files:** `Zombie.hpp`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`, `Makefile`

- `newZombie(name)` — allocates a `Zombie` on the **heap** and returns a pointer; caller is responsible for `delete`.
- `randomChump(name)` — creates a `Zombie` on the **stack**; destroyed automatically when the function returns.

The constructor calls `announce()` immediately, and the destructor prints `"Shooting <name> in the head..."`.

---

### ex01 — Moar brainz!

Allocates an entire horde of zombies in a **single `new[]` call**, then initialises each one individually via `setName()`.

**Key concepts:** `new[]`/`delete[]`, array allocation, `std::nothrow`, `std::stringstream` for name generation.

**Files:** `Zombie.hpp`, `Zombie.cpp`, `zombieHorde.cpp`, `main.cpp`, `Makefile`

- `zombieHorde(N, name)` — allocates `N` `Zombie` objects contiguously, names them `<name>1` … `<name>N`, and returns a pointer to the first. Returns `NULL` on invalid input or allocation failure (`std::nothrow`).
- Requires a default constructor (no-arg) since `new Zombie[N]` constructs before names are known.
- Caller deallocates with `delete[]`.

---

### ex02 — HI THIS IS BRAIN

Demystifies references by showing that a pointer and a reference to the same variable hold the same address and reflect mutations identically.

**Key concepts:** References vs pointers, address-of operator, reference semantics.

**Files:** `main.cpp`, `Makefile`

The program goes beyond the subject minimum — it also mutates the string via `line` and then via `stringREF`, confirming that all three aliases (`line`, `*stringPTR`, `stringREF`) stay in sync.

---

### ex03 — Unnecessary Violence

Explores the design decision of **reference vs pointer** for class members, using two nearly identical human classes that both hold a `Weapon`.

**Key concepts:** Reference members vs pointer members, `const` reference return, mutation observed through alias.

**Files:** `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `main.cpp`, `Makefile`

| Class | Weapon member | Why |
|-------|--------------|-----|
| `HumanA` | `Weapon &_theWeapon` (reference) | Always armed — weapon guaranteed at construction, reference is sufficient |
| `HumanB` | `Weapon *_theWeapon` (pointer) | Optionally armed — pointer can be `NULL`; weapon assigned later via `setWeapon()` |

`Weapon::getType()` returns a `const std::string &`, so `attack()` always reflects the weapon's current type even after `setType()` is called — no copy is made.

---

### ex04 — Sed is for Losers

A file manipulation utility that replaces all occurrences of `s1` with `s2` in a file, writing the result to `<filename>.replace`. `std::string::replace` is forbidden.

**Key concepts:** `std::ifstream`/`std::ofstream`, `std::string::find`, `std::string::substr`, manual replacement loop.

**Files:** `main.cpp`, `Makefile`

File is read entirely into a `std::string` using `std::getline` with `'\0'` as delimiter (avoids stopping at newlines). The replacement loop uses `find()` + `substr()` to rebuild the string, advancing the search position past the newly inserted `s2` to avoid infinite loops on overlapping patterns. Handles errors: wrong argument count, empty `s1`, unopenable files.

---

### ex05 — Harl 2.0

Automates a complaining character using an array of **pointers to member functions**, avoiding any `if/else` chain in `complain()`.

**Key concepts:** Pointers to member functions (`void (Harl::*f)(void)`), function pointer arrays, dispatch by index.

**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`, `Makefile`

`complain(level)` builds parallel arrays of level strings and function pointers, finds the matching index, then calls `(this->*functions[i])()`. If the level is unrecognised, Harl rejects it with a helpful message. Accepts multiple level arguments in a single run.

---

### ex06 — Harl Filter

Extends Harl 2.0 with a **minimum log level filter**: passing `WARNING` prints `WARNING` and everything above it. Uses `switch` fall-through deliberately.

**Key concepts:** `switch` fall-through, log level filtering, single-argument CLI programs.

**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`, `Makefile`

`complain()` maps the level string to an integer index, then enters a `switch` with **no `break` between cases** — execution falls through from the matched level to the end, printing all messages at that severity and above. An unrecognised level hits `default`.

---

## CPP02 — Orthodox Canonical Form and Operator Overloading

> The OCF requirement kicks in here. All exercises build a `Fixed` class representing a fixed-point number with 8 fractional bits.

### ex00 — My First Class in Orthodox Canonical Form

Introduces the **Orthodox Canonical Form** by implementing a minimal `Fixed` class with the four required members and nothing else useful yet.

**Key concepts:** OCF (default constructor, copy constructor, copy assignment operator, destructor), `static const` class members, `getRawBits`/`setRawBits`.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

The `Fixed` class stores a single `int _fixedPoint` and a `static const int _fractBit = 8`. Every special member function prints a diagnostic message, making the construction/copy/destruction sequence visible at runtime.

---

### ex01 — Towards a More Useful Fixed-Point Number Class

Adds **int and float constructors** and **conversion functions**, making `Fixed` actually represent fractional values.

**Key concepts:** Fixed-point arithmetic (left-shift for int→fixed, `roundf` for float→fixed), `toFloat()`/`toInt()`, `operator<<` overload.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

| Constructor / function | What it does |
|------------------------|-------------|
| `Fixed(int)` | Stores `val << 8` (integer part in upper bits) |
| `Fixed(float)` | Stores `roundf(val * 256)` |
| `toFloat()` | Returns `_fixedPoint / 256.0f` |
| `toInt()` | Returns `_fixedPoint >> 8` (truncates fractional part) |
| `operator<<` | Inserts `toFloat()` into the stream |

---

### ex02 — Now We're Talking

Adds the full operator suite to `Fixed`, making it usable as a numeric type.

**Key concepts:** Arithmetic operators (working on raw bits), comparison operators, pre/post increment/decrement (smallest ε = 1 raw bit), static `min`/`max` overloads for const and non-const.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Operators implemented:**

| Category | Operators |
|----------|-----------|
| Comparison | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Arithmetic | `+`, `-`, `*`, `/` |
| Increment/decrement | `++` (pre/post), `--` (pre/post) |
| Static utility | `min(a, b)`, `max(a, b)` (const and non-const overloads) |

Key details: multiplication shifts the result right by `_fractBit` to correct the representation; division shifts the dividend left before dividing. Division by zero prints an error and returns 0. Pre-increment/decrement modify `_fixedPoint` by 1 (smallest representable ε) and return `*this`; post-increment/decrement return a copy before the modification.

---
### ex03 — BSP (Binary Space Partitioning)

Uses the `Fixed` class to solve a computational geometry problem: determining whether a point lies **strictly inside** a triangle (not on an edge or vertex).

**Key concepts:** Fixed-point geometry, signed area / shoelace formula, BSP concept, `const` members in OCF classes.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`, `Makefile`

**`Point` class** — OCF, stores two `const Fixed` coordinates (`_x`, `_y`). Because the members are `const`, the copy assignment operator is a no-op (required by OCF but cannot actually reassign). Constructed from two `float` values via the `Fixed(float)` constructor.

**`bsp` algorithm** — uses the **shoelace / triangle area** method:

1. Compute the area of the full triangle ABC (`tArea`).
2. Compute the areas of the three sub-triangles formed with the test point: PAB, PBC, PCA.
3. If any sub-triangle has area 0, the point is on an edge or vertex → return `false`.
4. If the sum PAB + PBC + PCA ≈ ABC (within a fixed-point tolerance of ±0.01), the point is inside → return `true`.

`tArea` uses the cross-product form of the shoelace formula and takes the absolute value to handle winding order. The tolerance check (`±0.01f`) compensates for fixed-point rounding when comparing the summed sub-areas to the total.

---
## CPP03 — Inheritance

> Single and multiple inheritance, construction/destruction chaining, attribute access control (`protected`), and the diamond problem with virtual inheritance.

### ex00 — Aaaaand... OPEN!

The base class of the module: `ClapTrap`, a simple robot with hit points, energy points, and attack damage.

**Key concepts:** OCF, `protected` vs `private` attributes (anticipating inheritance), guarded actions (no energy → no attack/repair).

**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`, `Makefile`

| Attribute | Default |
|-----------|---------|
| `_name` | constructor parameter |
| `_hit` | 10 |
| `_energy` | 10 |
| `_attack` | 0 |

`attack()` and `beRepaired()` each cost 1 energy point and do nothing if energy is 0. `takeDamage()` subtracts directly from `_hit`. All actions print a descriptive message. Attributes are `private` in ex00 and changed to `protected` in ex01 to allow subclass access.

---

### ex01 — Serena, my love!

Adds `ScavTrap`, the first derived class — inherits from `ClapTrap` and overrides `attack()` with its own message and special ability.

**Key concepts:** Public inheritance, constructor/destructor chaining (base constructed first, destroyed last), attribute override via assignment in derived constructor body, `protected` access.

**Files:** + `ScavTrap.hpp`, `ScavTrap.cpp`

`ScavTrap` calls `ClapTrap(name)` in its initialiser list, then overrides the stats in the constructor body:

| Attribute | ScavTrap value |
|-----------|---------------|
| `_hit` | 100 |
| `_energy` | 50 |
| `_attack` | 20 |

Special ability: `guardGate()` — prints that ScavTrap has entered Gate keeper mode. `attack()` is overridden with a different message while reusing the same energy/guard logic.

---

### ex02 — Repetitive Work

Adds `FragTrap`, a second class inheriting from `ClapTrap`, parallel to `ScavTrap`.

**Key concepts:** Multiple sibling classes inheriting from the same base, distinct constructor/destructor messages, different stat values.

**Files:** + `FragTrap.hpp`, `FragTrap.cpp`

| Attribute | FragTrap value |
|-----------|---------------|
| `_hit` | 100 |
| `_energy` | 100 |
| `_attack` | 30 |

Special ability: `highFivesGuys()` — prints an enthusiastic high-five request. Uses `ClapTrap::operator=()` inside its own copy assignment operator to delegate the base-class copy, then re-applies the derived stats.

---
### ex03 — Now it's Weird! (DiamondTrap)

Combines `FragTrap` and `ScavTrap` into a single class via **multiple inheritance**, deliberately triggering the diamond problem and solving it with **virtual inheritance**.

**Key concepts:** Multiple inheritance, diamond problem, virtual inheritance, virtual base constructor called by the most-derived class, shadowed `_name` attribute.

**Files:** + `DiamondTrap.hpp`, `DiamondTrap.cpp`

**The diamond problem:** Without `virtual`, `DiamondTrap` would contain two separate `ClapTrap` sub-objects (one from `ScavTrap`, one from `FragTrap`). Both `ScavTrap` and `FragTrap` inherit from `ClapTrap` with `virtual public`, so there is only **one shared `ClapTrap` instance** — and its constructor must be called explicitly by `DiamondTrap` itself.

**`DiamondTrap` name duality:**

| Attribute | Value |
|-----------|-------|
| `DiamondTrap::_name` | the name passed to the constructor |
| `ClapTrap::_name` | same name + `"_clap_name"` suffix |

`whoAmI()` prints both. `getDiamondName()` returns `DiamondTrap::_name`; the inherited `getName()` returns `ClapTrap::_name`.

**Stats inherited from:**

| Stat | Source |
|------|--------|
| `_hit` (100) | `FragTrap::sci_hit` |
| `_energy` (50) | `ScavTrap::sci_energy` |
| `_attack` (30) | `FragTrap::sci_attack` |

`attack()` delegates to `ScavTrap::attack()`. Both `guardGate()` and `highFivesGuys()` are inherited and available. The stat constants (`sci_hit`, `sci_energy`, `sci_attack`) were promoted to `static const` members of `ScavTrap` and `FragTrap` in this exercise to allow `DiamondTrap` to reference them unambiguously.

**Construction order** (for `DiamondTrap("Mel")`):
1. `ClapTrap("Mel_clap_name")` — the virtual base, constructed once
2. `ScavTrap` (skips its own `ClapTrap` call due to virtual inheritance)
3. `FragTrap` (same)
4. `DiamondTrap`

**Destruction order** is the exact reverse.

---
## CPP04 — Subtype Polymorphism, Abstract Classes and Interfaces

> Virtual functions, pure virtual functions, abstract classes, virtual destructors, deep copies, and pure abstract classes as interfaces.

### ex00 — Polymorphism

Introduces **subtype polymorphism** via virtual functions: calling `makeSound()` through an `Animal*` dispatches to the correct derived class at runtime.

**Key concepts:** `virtual` functions, virtual destructor, dynamic dispatch, contrast with non-virtual behaviour.

**Files:** `Animal.hpp`, `Animal.cpp`, `Dog.hpp`, `Dog.cpp`, `Cat.hpp`, `Cat.cpp`, `WrongAnimal.hpp`, `WrongAnimal.cpp`, `WrongCat.hpp`, `WrongCat.cpp`, `main.cpp`, `Makefile`

**Class hierarchy:**

```
Animal          WrongAnimal
  ├── Dog           └── WrongCat
  └── Cat
```

`Animal::makeSound()` is `virtual`; `WrongAnimal::makeSound()` is not. This means:

| Pointer type | Object | `makeSound()` call goes to |
|---|---|---|
| `Animal*` | `Dog` | `Dog::makeSound()` ✓ |
| `Animal*` | `Cat` | `Cat::makeSound()` ✓ |
| `WrongAnimal*` | `WrongCat` | `WrongAnimal::makeSound()` ✗ (no virtual) |

`Animal`'s destructor is `virtual` so that `delete animal_ptr` calls the correct derived destructor when objects are deleted through a base pointer. `WrongAnimal`'s destructor is not virtual — demonstrating the leak/wrong-destructor risk.

---
### ex01 — I Don't Want to Set the World on Fire

Adds a `Brain` class and forces **deep copy** semantics on `Dog` and `Cat`.

**Key concepts:** Deep copy vs shallow copy, heap-allocated members, `new`/`delete` in copy constructor and copy assignment operator, virtual `clone()` pattern.

**Files:** + `Brain.hpp`, `Brain.cpp` (updated `Dog`, `Cat`, `Animal`)

**`Brain`** — stores an array of 100 `std::string ideas`. Copy constructor and copy assignment operator iterate all 100 slots to perform a full value copy. `addIdea()` finds the first empty slot; `getIdea()`/`setIdea()` do bounds-checked access.

**Deep copy in `Dog` and `Cat`:**
- Constructor: `_dogBrain = new Brain()` / `_catBrain = new Brain()`
- Copy constructor: `_dogBrain = new Brain(*other._dogBrain)` — allocates a new `Brain` and copies all ideas
- Copy assignment: `delete`s the existing brain before `new Brain(*other._dogBrain)`
- Destructor: `delete _dogBrain` / `delete _catBrain` before printing the destruction message

This ensures that copying a `Dog` or `Cat` never shares a `Brain` pointer between two objects (no dangling pointer on destruction, no idea bleed-through).

**`clone()` virtual method** — added to `Animal` and overridden in `Dog`/`Cat`. Returns `new Dog(*this)` / `new Cat(*this)`, giving a type-safe deep copy through a base pointer without `dynamic_cast`. Calling `rawCopy = new Dog(*(Dog*)animalPtr)` is noted in the test as undefined behaviour when the pointer's actual type is unknown.

**Array test** — `main` allocates an `Animal*` array with alternating `Dog`/`Cat` objects, exercises `addIdea`/`rememberIdea` through the base pointer, then deletes every element via `Animal*` (safe because the destructor is `virtual`).

---
### ex02 — Abstract Class

Makes `Animal` non-instantiable by converting it into an **abstract class** (`AAnimal`), with `makeSound()`, `addIdea()`, `rememberIdea()`, and `clone()` all declared as **pure virtual** (`= 0`).

**Key concepts:** Pure virtual functions, abstract classes, preventing instantiation at compile time.

**Files:** `AAnimal.hpp`, `AAnimal.cpp` (replaces `Animal`; all other files updated accordingly)

The only change from ex01 is that `Animal` is renamed `AAnimal` and its four virtual methods become pure virtual:

```cpp
virtual void        makeSound()  const = 0;
virtual void        addIdea(const std::string &idea) = 0;
virtual std::string rememberIdea(int index) const = 0;
virtual AAnimal*    clone() const = 0;
```

`AAnimal` still provides a constructor, copy constructor, copy assignment operator, and virtual destructor — the OCF is intact even though the class is abstract. `Dog` and `Cat` are unchanged apart from inheriting from `AAnimal` instead of `Animal`. Attempting `AAnimal test;` in `main` is left as a commented-out line that would produce a compile error.

---
### ex03 — Interface & Recap

Implements a full **interface-based design** in C++98 using pure abstract classes as interfaces, with concrete implementations wired together through those interfaces.

**Key concepts:** Pure abstract classes as interfaces, forward declarations, `clone()` pattern for polymorphic copying, memory ownership and leak prevention with unequipped Materias.

**Files:** `AMateria.hpp/cpp`, `ICharacter.hpp`, `IMateriasource.hpp`, `Character.hpp/cpp`, `MateriaSource.hpp/cpp`, `Ice.hpp/cpp`, `Cure.hpp/cpp`, `main.cpp`, `Makefile`

**Class structure:**

```
ICharacter (interface)          IMateriaSource (interface)
    └── Character                   └── MateriaSource

AMateria (abstract)
    ├── Ice
    └── Cure
```

**`AMateria`** — abstract base with a `_type` string, `getType()`, pure virtual `clone()`, and a default-no-op `use()`. Copying the type in the assignment operator is intentionally skipped (assigning a Materia to another doesn't change its type).

**`Ice` / `Cure`** — concrete Materias. `clone()` returns `new Ice(*this)` / `new Cure(*this)`. `use()` prints the effect using the target's name.

**`Character`** — holds a 4-slot `_inventory[4]` (active Materias) and a 100-slot `_bag[100]` (unequipped Materias not yet deleted). Key behaviours:
- `equip(m)` — places `m` in the first `NULL` slot; if full, deletes `m` immediately.
- `unequip(idx)` — moves the pointer to `_bag` (does **not** delete it); the bag is cleaned up on destruction.
- `use(idx, target)` — calls `_inventory[idx]->use(target)`, then deletes and nulls the slot.
- `use(type, target)` — extra overload to fire by type string (beyond the subject minimum).
- Deep copy: clones every non-null inventory slot and every bag entry; the copy gets a `"_copy"` name suffix.

**`MateriaSource`** — stores up to 4 Materia templates in `_storage[4]`. `learnMateria(m)` takes ownership of `m`. `createMateria(type)` scans for a matching type and returns `clone()` of the template, or `NULL` if unknown.

**Memory management:** `_clearInventory()` and `_clearBag()` are private helpers called in the destructor and copy assignment to prevent leaks. `unequip()` never deletes — the caller or the Character's destructor is responsible.

---
## CPP05 — Repetition and Exceptions

> C++ exception handling (`throw`/`try`/`catch`), nested exception classes, `const` member attributes, and abstract forms with concrete actions.

### ex00 — Mommy, When I Grow Up, I Want to Be a Bureaucrat!

Introduces C++ exceptions through a `Bureaucrat` class whose grade is strictly bounded between 1 (highest) and 150 (lowest).

**Key concepts:** `throw`, `try`/`catch`, nested exception classes inheriting from `std::exception`, `const` name member, grade bounds enforcement.

**Files:** `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`, `Makefile`

`Bureaucrat` has a `const std::string _name` and an `int _grade`. The constructor, `incrementGrade()`, and `decrementGrade()` all throw nested exceptions on out-of-range grades:

| Exception | Condition |
|-----------|-----------|
| `GradeTooHighException` | grade < 1 |
| `GradeTooLowException` | grade > 150 |

Both nested classes inherit from `std::exception` and override `what()`. The copy assignment operator can only copy `_grade` (not `_name`, which is `const`). `operator<<` prints `"<name>, bureaucrat grade <grade>."`.

The test creates bureaucrats with valid and invalid grades, exercises increment/decrement past the limits inside `try`/`catch` blocks, and demonstrates copy and assignment.

---

### ex01 — Form Up, Maggots!

Adds a `Form` class with its own grade constraints and a signing mechanism that ties `Bureaucrat` and `Form` together.

**Key concepts:** Cross-class exception propagation, `const` member initialisation in constructors, forward declarations, `signForm` delegating to `beSigned`.

**Files:** + `Form.hpp`, `Form.cpp` (updated `Bureaucrat`)

`Form` has four private attributes — `const _name`, `bool _isSigned`, `const _toSignGrade`, `const _toExecGrade` — all validated at construction via a file-static `checkGrade()` helper that throws `Form::GradeTooHighException` / `Form::GradeTooLowException`.

`beSigned(bureaucrat)` checks `bureaucrat.getGrade() <= _toSignGrade`; if not, throws `GradeTooLowException`. `Bureaucrat::signForm(form)` calls `form.beSigned(*this)` inside a `try`/`catch` and prints success or failure with the reason.

The test creates bureaucrats of varying grades, a batch of forms with randomised (and sometimes deliberately invalid) grade requirements, and runs every bureaucrat through every form — demonstrating which combinations succeed and which throw.

---
### ex02 — No, You Need Form 28B, Not 28C...

Renames `Form` to `AForm` (abstract), adds `execute()` to the base class, and implements three concrete form types that each do something real.

**Key concepts:** Abstract base class, pure virtual `executeAction()`, template method pattern (`execute()` validates then calls `executeAction()`), file output, randomness, `std::ofstream`.

**Files:** `AForm.hpp/cpp`, `ShrubberyCreationForm.hpp/cpp`, `RobotomyRequestForm.hpp/cpp`, `PresidentialPardonForm.hpp/cpp`, updated `Bureaucrat`

**`AForm`** adds:
- `virtual void executeAction() const = 0` (protected pure virtual — the hook)
- `void execute(Bureaucrat const &executor) const` — checks signed status and executor grade, then calls `executeAction()`. Also adds `FormNotSignedException`.
- `Bureaucrat::executeForm(AForm const &form)` — wraps `execute()` in a `try`/`catch`.

**Concrete forms:**

| Form | Sign grade | Exec grade | Action |
|------|-----------|-----------|--------|
| `ShrubberyCreationForm` | 145 | 137 | Writes ASCII tree to `<target>_shrubbery` file using `std::ofstream`; tree height randomised (3–7 rows) |
| `RobotomyRequestForm` | 72 | 45 | Prints drilling noises; 50% chance of success via `std::rand() % 2` |
| `PresidentialPardonForm` | 25 | 5 | Prints that target has been pardoned by Zaphod Beeblebrox |

The test creates five bureaucrats at calibrated grade ranges (covering the spectrum from 1 to 150), then for each of the three form types runs a batch of 10 forms through the full sign → execute cycle, demonstrating which bureaucrats have sufficient grade for each step.

---
### ex03 — At Least This Beats Coffee-Making

Adds an `Intern` class that creates forms by name without any `if/else if` chains, using a function pointer dispatch table instead.

**Key concepts:** Function pointer arrays as a dispatch table, avoiding `if/else` forests, factory pattern, OCF on a stateless class.

**Files:** + `Intern.hpp`, `Intern.cpp`

`Intern` has no attributes — it's a pure factory. `makeForm(name, target)` works by maintaining two parallel arrays: one of known form name strings and one of `static` private factory functions (`createShrubbery`, `createRobotomy`, `createPardon`), all typed as `AForm* (*)(const std::string&)`. A single loop matches `name` against the string array and calls the corresponding function pointer.

If the name doesn't match any known form, it prints an error and returns `NULL` — no exception thrown. The test generates 15 random forms via the `Intern` (mix of all three types), puts them through the full sign → execute cycle with the five-bureaucrat staff, and then attempts four nonsensical form names to confirm graceful rejection.

Because `Intern` is stateless, the copy constructor and copy assignment operator are no-ops.

---
## CPP06 — C++ Casts

> The four C++ cast operators: `static_cast`, `reinterpret_cast`, `dynamic_cast`, and `const_cast`. Each exercise focuses on a different one.

### ex00 — Conversion of Scalar Types

A non-instantiable `ScalarConverter` class with a single static method `convert(string)` that detects the type of a C++ literal and prints it as `char`, `int`, `float`, and `double`.

**Key concepts:** `static_cast`, type detection from string, `std::numeric_limits`, `std::strtod`, pseudo-literals (`nan`, `inf`), non-instantiable class pattern.

**Files:** `ScalarConverter.hpp`, `ScalarConverter.cpp`, `main.cpp`, `Makefile`

Non-instantiability is enforced by making all constructors and the destructor **private**.

**Detection pipeline** (`convert` → private helpers):

| Helper | Detects |
|--------|---------|
| `isPseudoLiteral` | `nan`, `nanf`, `±inf`, `±inff` |
| `isChar` | Single non-digit character |
| `isNumber` | Signed/unsigned integer, float (`f` suffix), double |

**Output helpers:**
- `outputPseudoLiteral` — uses `std::numeric_limits<float/double>::quiet_NaN()` and `::infinity()`; char and int always `impossible`.
- `outputChar` — converts the char directly via `static_cast`; checks `std::isprint` for display.
- `outputNumbers` — converts the string to `double` via `strtod`, then `static_cast`s to `float`/`int`/`char` with range checks against `std::numeric_limits`; prints `impossible` on overflow.

---

### ex01 — Serialization

Demonstrates `reinterpret_cast` by converting a `Data*` pointer to a `uintptr_t` integer and back, proving pointer identity is preserved.

**Key concepts:** `reinterpret_cast`, `uintptr_t`, pointer-to-integer and integer-to-pointer round-trip, non-instantiable class.

**Files:** `Serializer.hpp`, `Serializer.cpp`, `Data.hpp`, `Data.cpp`, `main.cpp`, `Makefile`

`Serializer` has two static methods — both private-constructor non-instantiable like `ScalarConverter`:
- `serialize(Data*)` → `reinterpret_cast<uintptr_t>(ptr)`
- `deserialize(uintptr_t)` → `reinterpret_cast<Data*>(raw)`

`Data` has two public members (`int id`, `double value`) with defaults (42 and 0.33). The test serialises the address of a stack `Data` object, deserialises it back, and confirms that the resulting pointer compares equal to the original address and that the member values are accessible and identical.

---
### ex02 — Identify Real Type

Uses `dynamic_cast` to identify the actual runtime type of a `Base*` or `Base&`, without `std::typeinfo` or the `<typeinfo>` header.

**Key concepts:** `dynamic_cast` with pointers (returns `NULL` on failure) vs references (throws `std::bad_cast` on failure), runtime type identification (RTTI), virtual destructor as the minimum requirement for a polymorphic base.

**Files:** `Base.hpp`, `Base.cpp`, `A.hpp`, `B.hpp`, `C.hpp`, `identify.hpp`, `identify.cpp`, `main.cpp`, `Makefile`

`Base` has only a `virtual ~Base()` — the virtual destructor is what makes RTTI possible. `A`, `B`, and `C` are empty classes inheriting from `Base`.

**`generate()`** — uses `rand() % 3` in a `switch` to return a `new A`, `new B`, or `new C` as a `Base*`.

**`identify(Base* p)`** — tries `dynamic_cast<A*>(p)`, `<B*>`, `<C*>` in sequence; prints the first non-NULL result.

**`identify(Base& p)`** — tries `dynamic_cast<A&>(p)` inside a `try` block; a failed reference cast throws `std::bad_cast`, which is caught and silently ignored before trying the next type. No pointers used inside this overload.

The test runs 10 rounds, printing both the pointer and reference identification for each randomly generated object.

---
## CPP07 — C++ Templates

> Function templates, class templates, and template instantiation. First module where STL containers and algorithms are still forbidden — the goal is to implement generic behaviour from scratch.

### ex00 — Start with a Few Functions

Three generic utility function templates defined entirely in a header file.

**Key concepts:** Function templates, type deduction, `template <typename T>`, header-only implementation requirement for templates.

**Files:** `whatever.hpp`, `main.cpp`, `Makefile`

| Template | Behaviour |
|----------|-----------|
| `swap<T>(T&, T&)` | Swaps two values of the same type in-place via a temp variable |
| `min<T>(const T&, const T&)` | Returns the smaller of two values; returns the second if equal |
| `max<T>(const T&, const T&)` | Returns the greater of two values; returns the second if equal |

Works on any type that supports `<` and `>`. The test calls all three with `int` and `std::string`.

---

### ex01 — Iter

A generic `iter` function template that applies a function to every element of an array, with two overloads to handle both const and non-const arrays.

**Key concepts:** Function templates with function pointer parameters, const-correctness in templates, two overloads for `T*` and `const T*`.

**Files:** `iter.hpp`, `main.cpp`, `Makefile`

```cpp
template <typename T>
void iter(T *ptr, const size_t len, void (*f)(T &));

template <typename T>
void iter(const T *ptr, const size_t len, void (*f)(const T &));
```

The two overloads ensure that passing a `const` array only accepts a function taking `const T&`, while a non-const array accepts functions taking `T&` (mutable) or `const T&` (read-only). Each call also prints the function pointer address for visibility. The test exercises all combinations: `print`, `inc`, `printConst`, `printT`, `printConstT` on both mutable and const int arrays.

---

### ex02 — Array

A generic `Array<T>` class template wrapping a heap-allocated array with bounds checking and deep copy semantics.

**Key concepts:** Class templates, `new T[n]`, `operator[]` with `std::exception` on out-of-bounds, `const` overload of `operator[]`, `.tpp` implementation file included from the header.

**Files:** `Array.hpp`, `Array.tpp`, `main.cpp`, `Makefile`

| Member | Behaviour |
|--------|-----------|
| `Array()` | Creates empty array (`_data = NULL`, `_size = 0`) |
| `Array(unsigned int n)` | Allocates `new T[n]` — each element default-initialised |
| Copy constructor / `operator=` | Deep copy: allocates a new `T[n]` and copies each element |
| `operator[](index)` | Throws `std::exception` if index ≥ `_size`; both const and non-const overloads |
| `size() const` | Returns `_size` |

Template implementation lives in `Array.tpp`, which is `#include`d at the bottom of `Array.hpp` — the standard pattern for separating template declarations from definitions without a `.cpp` file.

Key implementation notes from `Array.tpp`:
- `Array(unsigned int n)` uses `new T[n]()` — the `()` triggers value-initialisation (zero for scalars, default constructor for objects).
- Copy constructor allocates a fresh `new T[other.size()]()` then copies each element individually — no `memcpy`, guaranteeing correct deep copy for any `T`.
- `operator=` does `delete[] _data` before reallocating, preventing a memory leak; self-assignment is guarded.
- Both `operator[]` overloads throw a plain `std::exception()` on out-of-bounds (index ≥ `_size`). Since `index` is `unsigned int`, negative indices wrap around and are also caught by the ≥ check.

---
## CPP08 — Templated Containers, Iterators, Algorithms

> First module where STL containers (`vector`, `list`, `map`, etc.) and algorithms (`<algorithm>`) are not only allowed but required.

### ex00 — Easy Find

A single function template `easyfind` that searches any STL container of integers for a value using `std::find`.

**Key concepts:** Function templates with STL containers, `std::find`, iterator return, `<algorithm>`.

**Files:** `easyfind.hpp`, `main.cpp`, `Makefile`

```cpp
template <typename T>
typename T::const_iterator easyfind(const T &container, int toFind);
```

Returns `container.end()` if not found (same convention as `std::find`). Works on any container that supports `begin()`/`end()` and holds `int`. Tested against `std::vector`, `std::list`, and `std::deque`.

---

### ex01 — Span

A `Span` class that stores up to N integers and can compute the shortest and longest span (distance) between any two stored values.

**Key concepts:** `std::vector`, `std::sort`, `std::min_element`/`std::max_element`, range-based `addNumber` template, iterator range insertion.

**Files:** `Span.hpp`, `Span.cpp`, `main.cpp`, `Makefile`

| Method | Behaviour |
|--------|-----------|
| `addNumber(int)` | Appends one value; throws `std::exception` if full |
| `addNumber(It first, It last)` | Template range insert via `_arr.insert`; checks capacity first with `std::distance` |
| `shortestSpan()` | Sorts a copy, walks adjacent pairs; throws if ≤ 1 element |
| `longestSpan()` | Returns `max_element - min_element`; throws if ≤ 1 element |

`_arr` is a `std::vector<int>`; `_maxSize` is set at construction and never changes. The test covers the subject example, overflow cases for both single and range adds, edge cases (1 element), mixed-source range add, and a 10 000-element stress test.

---

### ex02 — Mutated Abomination (MutantStack)

Makes `std::stack` iterable by inheriting from it and exposing the underlying container's iterators.

**Key concepts:** Template class inheritance from STL container, `container_type`, exposing `iterator` typedef, `begin()`/`end()` delegation to the underlying `deque`.

**Files:** `MutantStack.hpp`, `MutantStack.tpp`, `main.cpp`, `Makefile`

`std::stack` wraps a `std::deque` (by default) but hides its iterators. `MutantStack<T>` inherits `public std::stack<T>` and adds:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
iterator begin();
iterator end();
```

`begin()` and `end()` delegate to `this->c.begin()` / `this->c.end()` — `c` is the `protected` underlying container member of `std::stack`. The OCF in `MutantStack.tpp` delegates entirely to `std::stack<T>`: the copy constructor calls `std::stack<T>(other)` and `operator=` calls `std::stack<T>::operator=(other)`. Public inheritance means `std::stack<int> s(mstack)` in the test works directly via intentional slicing. The test matches the subject example exactly, then is cross-validated against `std::list` and `std::vector` (both commented out) to confirm identical output.

---
## CPP09 — STL

> Final module. Each exercise must use a different STL container — once used, a container is off-limits for the remaining exercises.

**Container assignments:** `std::map` → ex00 | `std::stack` → ex01 | `std::vector` + `std::deque` → ex02

### ex00 — Bitcoin Exchange

A `btc` program that reads a historical BTC price database (`data.csv`) and an input file, then outputs each entry's value multiplied by the closest earlier exchange rate.

**Key concepts:** `std::map`, `lower_bound` for closest-date lookup, CSV parsing, date and value validation, `std::ifstream`.

**Files:** `BitcoinExchange.hpp`, `BitcoinExchange.cpp`, `main.cpp`, `data.csv`, `Makefile`

`_baseData` is a `std::map<std::string, float>` — string dates sort lexicographically in ISO format, so `lower_bound(date)` finds the insertion point efficiently. If the exact date isn't in the map, the iterator is decremented to get the closest earlier date.

**Validation pipeline:**

| Check | Error message |
|-------|--------------|
| Missing ` \| ` separator | `Bad format =>` |
| Invalid date format/range | `Invalid date…` / `Invalid month…` / `Day is invalid…` |
| Negative value | `Not a positive number =>` |
| Value > 1000 | `Too large a number =>` |
| No DB data before date | `No data for this date =>` |

Date validation checks length, `-` positions, digit-only fields, valid month (1–12), and day within month including leap year handling.

---

### ex01 — Reverse Polish Notation

An `RPN` program that evaluates a postfix arithmetic expression passed as a command-line argument.

**Key concepts:** `std::stack`, postfix evaluation, operator precedence implicit in RPN, input validation.

**Files:** `RPN.hpp`, `RPN.cpp`, `main.cpp`, `Makefile`

`_operands` is a `std::stack<int>`. `thinkMath()` validates the input first (each token must be exactly one character — a single digit or one of `+-*/`), then scans left to right: digits are pushed, operators pop two operands, compute, and push the result. Division by zero throws. If at the end the stack doesn't have exactly one element, it throws `"Error"`.

---

### ex02 — PmergeMe (Ford-Johnson Sort)

A `PmergeMe` program that sorts a sequence of positive integers using the **merge-insert (Ford-Johnson) algorithm**, implemented independently for both `std::vector` and `std::deque`, then reports the time taken by each.

**Key concepts:** Ford-Johnson algorithm, Jacobsthal sequence for insertion order, binary search insertion, `std::vector`, `std::deque`, `std::clock` for timing.

**Files:** `PmergeMe.hpp`, `PmergeMe.cpp`, `main.cpp`, `Makefile`

**Algorithm (`sortPMergeMe`):**
1. Pair adjacent elements; send the smaller to `lesserV`, the larger to `biggerV`. Track any leftover odd element.
2. Recursively sort `biggerV`.
3. Generate a Jacobsthal-order insertion sequence for `lesserV` — this minimises the number of comparisons needed.
4. Binary-search insert each `lesserV` element into `biggerV` in Jacobsthal order.
5. Insert the leftover element last.

The same algorithm is implemented twice — once for `std::vector`, once for `std::deque` — both measured separately with `std::clock`. Handles ≥ 3000 elements. Input validation rejects non-integers, negative values, and values exceeding `INT_MAX`.

---
