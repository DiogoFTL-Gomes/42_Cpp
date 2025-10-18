#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed() : _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int val){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = val << this->_fractBit;
}

Fixed::Fixed(const float val){
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(val * (1 << this->_fractBit));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw){
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const{
	return (_fixedPoint / 256.0f);
}

int		Fixed::toInt(void) const{
	return (_fixedPoint >> _fractBit);
}


std::ostream	&operator<<(std::ostream &out, const Fixed &value){
	out << value.toFloat();
	return out;
}
