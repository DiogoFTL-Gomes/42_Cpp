#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif