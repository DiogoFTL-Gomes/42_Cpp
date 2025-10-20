#ifndef FIXED_H
# define FIXED_H

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

class	Fixed{
	public:
	//constructors/destructors
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();

	//operator overloads
		Fixed	&operator=(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		bool	operator==(const Fixed &other) const;//
		bool	operator!=(const Fixed &other) const;//
		bool	operator>=(const Fixed &other) const;//
		bool	operator<=(const Fixed &other) const;//
		bool	operator>(const Fixed &other) const;//
		bool	operator<(const Fixed &other) const;//

	//Get/set/converters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	//Min/Max
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);


	private:
		int					_fixedPoint;
		static const int	_fractBit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
