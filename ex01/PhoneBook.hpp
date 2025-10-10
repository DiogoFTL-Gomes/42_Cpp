#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	put_menu(void) const;
		void	check_input(std::string	line) const;
		void	eof_input(void) const;

		void	add_nbr_contacts();
		int		get_nbr_contacts();

	private:
		Contact	_contacts[8];
		int		_nbr_contacts;

};

#endif
