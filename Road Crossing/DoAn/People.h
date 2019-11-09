#pragma once

#include"Console.h"

class People
{
private:
	int _x, _y;
	bool _state;
	int _level;
public:
	People() { _x = 0; _y = 0; _state = 0; _level = 0; }
	People(int x, int y, int z) { _x = x; _y = y; _state = 0; _level = z; }
	bool getState() { return _state; }
	int getLevel() { return _level; }
	void setState(bool x) { _state = x; }
	void setXY(int x, int y) { _x = x; _y = y; }
	void setLevel(int x) { _level = x; }
	int getX() { return _x; }
	int getY() { return _y; }
	void drawSpace();
	void drawPlayer();
	void up();
	void left();
	void right();
	void down();
};