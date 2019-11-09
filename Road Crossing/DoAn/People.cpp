#include"People.h"

void People::drawSpace()
{
	goToXY(_x, _y);
	cout << " ";
}

void People::drawPlayer()
{
	goToXY(_x, _y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 - _level);
	cout << "Y";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void People::up()
{
	if (_y > 1)
	{
		drawSpace();
		_y--;
		drawPlayer();
	}
}

void People::left()
{
	if (_x > 1)
	{
		drawSpace();
		_x--;
		drawPlayer();
	}
}

void People::right()
{
	if (_x < 79)
	{
		drawSpace();
		_x++;
		drawPlayer();
	}
}

void People::down()
{
	if (_y < 19)
	{
		drawSpace();
		_y++;
		drawPlayer();
	}
}