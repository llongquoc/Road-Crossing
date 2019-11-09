#pragma once

#include"Console.h"

class Vehicle
{
protected:
	int _x, _y;
	int _speed;
public:
	Vehicle() { _x = 0; _y = 0; }
	int getSpeed() { return _speed; }
	void setSpeed(int speed) { _speed = speed; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	int getX() { return _x; }
	int getY() { return _y; }
	void drawVehicle() { goToXY(_x, _y); }
	Vehicle& operator = (const Vehicle &p);
};