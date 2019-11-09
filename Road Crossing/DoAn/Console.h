#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>
#include<time.h>
#include<thread>
#include<vector>
#include<windows.h>
#include<MMSystem.h>
#include<fstream>

using namespace std;

#define WIDTH_CONSOLE 115
#define HEIGH_CONSOLE 28

void fixConsoleWindow();
void goToXY(int x, int y);
void clrscr();