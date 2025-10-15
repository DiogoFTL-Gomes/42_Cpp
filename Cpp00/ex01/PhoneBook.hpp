#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

typedef enum	e_field{
	FIRSTN,
	LASTN,
	NICKN,
	NUMBER,
	DARKS
}	t_field;

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int			get_nbr_contacts() const;
		int			get_total_contacts() const;
		void		set_contacts(std::string *values, int i);
		std::string	get_contacts(int i, t_field field);



	private:
		Contact	_contacts[8];
		int		_nbr_contacts;
		int		_total_contacts;

		void	_add_current_contacts();


};

#endif
