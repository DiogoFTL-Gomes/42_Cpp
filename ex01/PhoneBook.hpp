#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);


		int		start_menu(void);
		void	start_draw(void) const;
		int		start_input(std::string	*line);
		void	add_draw(void) const;
		int		add_menu(void);
		int		search_menu(void) const;
		void	search_draw(void) const;
		int		search_input(std::string *line) const;
		void	search_print() const;
		void	eof_input(void) const;



	private:
		Contact	_contacts[8];
		int		_nbr_contacts;

		void	_add_nbr_contacts();
		int		_get_nbr_contacts() const;

};

#endif
