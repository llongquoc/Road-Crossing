#pragma once

#include"People.h"
#include"Truck.h"
#include"Car.h"
#include"Dinausor.h"
#include"Bird.h"

#define MAX_TRUCK_LENGTH 4
#define MAX_CAR_LENGTH 4
#define MAX_DINAUSOR_LENGTH 4
#define MAX_BIRD_LENGTH 4
#define MAX_TRUCK 16
#define MAX_CAR 16
#define MAX_DINAUSOR 16
#define MAX_BIRD 16

struct record
{
	clock_t t;
	char name[100];
};

class Game
{
private:
	People *_player;
	Truck **_t;
	Car **_c;
	Dinausor **_d;
	Bird **_b;
	int _numberOfTruck;
	int _numberOfCar;
	int _numberOfDinausor;
	int _numberOfBird;
	clock_t _beginTime, _time;
	record _top[5];
	int _stop[10];
public:
	Game();
	~Game();
	People* getPlayer() { return _player; }
	void up() { _player->up(); }
	void left() { _player->left(); }
	void right() { _player->right(); }
	void down() { _player->down(); }
	void drawGame(int x, int y, int width, int height);
	void loadFile();
	void saveFile();
	void resetGame();
	void startGame();
	void exitGame(HANDLE t);
	void pauseGame(HANDLE t);
	void processDead();
	void processWin(int T);
	void processFinish();
	void create();
	void drawTruck();
	void drawCar();
	void drawDinausor();
	void drawBird();
	bool isImpact(int t);
	void moveTruck();
	void moveCar();
	void moveDinausor();
	void moveBird();
	void eraseTruck();
	void eraseCar();
	void eraseDinausor();
	void eraseBird();
	bool stopMark(int i);
	void drawMenu();
	void drawInstruction();
	void drawImpact();
	void drawIcon();
	void drawStart();
	void drawLoading();
	void drawTrafficLight();
	void setRecord();
	int isRecord(clock_t t);
	clock_t getBeginTime() { return _beginTime; }
	clock_t getTime() { return _time; }
	void setBeginTime(clock_t t) { _beginTime = t; }
	void setTime(clock_t t) { _time = t; }
	Bird getBird() { return _b[0][0]; }
	int getStop(int i) { return _stop[i]; }
	void setStop(int i, int value) { _stop[i] = value; }
};