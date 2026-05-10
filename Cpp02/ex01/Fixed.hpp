#ifndef FIXED_H
# define FIXED_H

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

class	Fixed{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int val);
		Fixed(const float val);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedPoint;
		static const int	_fractBit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
