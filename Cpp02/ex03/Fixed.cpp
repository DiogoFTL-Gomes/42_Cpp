#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

//constructors/destructors
Fixed::Fixed() : _fixedPoint(0){
}
Fixed::Fixed(const Fixed &other){
	*this = other;
}
Fixed::Fixed(const int val){
	this->_fixedPoint = val << this->_fractBit;
}
Fixed::Fixed(const float val){
	this->_fixedPoint = roundf(val * (1 << this->_fractBit));
}
Fixed::~Fixed(){
}

//operator overloads
Fixed	&Fixed::operator=(const Fixed &other){
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

//Comparison overload
bool	Fixed::operator==(const Fixed &other) const{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const{
	return (this->getRawBits() != other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const{
	return (this->getRawBits() < other.getRawBits());
}

//Increment/decrement overload
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
	return (this->_fixedPoint);
}
void	Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
}
float	Fixed::toFloat(void) const{
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
