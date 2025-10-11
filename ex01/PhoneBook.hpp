#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		start_menu() const;
		void	draw_start(void) const;
		int		start_input(std::string	*line) const;
		void	add_menu(void) const;
		void	add_input(void) const;
		void	search_menu(void) const;
		void	search_input(void) const;
		void	eof_input(void) const;


	private:
		Contact	_contacts[8];
		int		_nbr_contacts;

		void	_add_nbr_contacts();
		int		_get_nbr_contacts() const;

};

#endif
