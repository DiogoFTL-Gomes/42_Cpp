#include "Point.hpp"


Point::Point() : _x(0), _y(0){//constructor
}

Point::Point(const float x, const float y) : _x(x), _y(y){//constructor with values
}

Point::Point(const Point &other) : _x(other._x), _y(other._y){//copy constructor
}

Point::~Point(){//destructor
}

//operator overload
Point	&Point::operator=(const Point &other){//Useless copy assignment operator overload
	(void)other;
	return (*this);
}

Fixed	Point::getX() const{
	return this->_x;
}

Fixed	Point::getY() const{
	return this->_y;
}