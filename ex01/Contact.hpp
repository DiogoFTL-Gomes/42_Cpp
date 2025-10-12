#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
