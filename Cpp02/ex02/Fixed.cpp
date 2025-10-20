#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

//constructors/destructors
Fixed::Fixed() : _fixedPoint(0){
	//std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other){
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int val){
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = val << this->_fractBit;
}
Fixed::Fixed(const float val){
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(val * (1 << this->_fractBit));
}
Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

//operator overloads
Fixed	&Fixed::operator=(const Fixed &other){
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other){
	Fixed	res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &other){
	Fixed	res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other){
	Fixed	res;
	res.setRawBits((this->getRawBits() * other.getRawBits()) >> this->_fractBit);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other){
	if (other.getRawBits() == 0){
		std::cerr << "Division by zero is a big no no. Take a zero" << std::endl;
		return (Fixed(0));
	}
	Fixed	res;
	res.setRawBits((this->getRawBits() << this->_fractBit) / other.getRawBits());
	return (res);
}

Fixed	&Fixed::operator++(void){
	++this->_fixedPoint;
	return (*this);
}
Fixed	Fixed::operator++(int){
	Fixed temp(*this);
	this->_fixedPoint++;
	return (temp);
}
Fixed	&Fixed::operator--(void){
	--this->_fixedPoint;
	return (*this);

}
Fixed	Fixed::operator--(int){
	Fixed temp(*this);
	this->_fixedPoint--;
	return (temp);
}
//Get/set/converters
int		Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}
void	Fixed::setRawBits(int const raw){
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}
float	Fixed::toFloat(void) const{
	//return ((float)_fixedPoint / (1 << _fractBit));
	return (_fixedPoint / 256.0f);
}
int		Fixed::toInt(void) const{
	return (_fixedPoint >> _fractBit);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	return (a > b) ? a : b;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value){
	out << value.toFloat();
	return out;
}
