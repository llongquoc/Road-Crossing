#include"Vehicle.h"

Vehicle& Vehicle::operator = (const Vehicle &p)
{
	_x = p._x;
	_y = p._y;
	_speed = p._speed;
	return *this;
}