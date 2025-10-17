#ifndef FIXED_H
# define FIXED_H

class	Fixed{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBit(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractBit = 8;
};

#endif
