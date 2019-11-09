#include"Game.h"

Game::Game()
{
	int tempTruck[16];
	int tempCar[16];
	int tempDinausor[16];
	int tempBird[16];
	_numberOfTruck = 8;
	_numberOfCar = 8;
	_numberOfDinausor = 8;
	_numberOfBird = 8;
	_player = new People(18, 19, 0);
	_t = new Truck*[MAX_TRUCK];
	for (int i = 0; i < _numberOfTruck; i++)
		_t[i] = new Truck[MAX_TRUCK_LENGTH];
	for (int i = 0; i < _numberOfTruck; i++)
	{
		tempTruck[i] = (rand() % (79 - MAX_TRUCK_LENGTH)) + 1;
		for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
		{
			_t[i][j].setX(tempTruck[i] + j);
			_t[i][j].setY(2 + i);
			_t[i][j].setSpeed(1);
		}
	}
	_c = new Car*[MAX_CAR];
	for (int i = 0; i < _numberOfCar; i++)
		_c[i] = new Car[MAX_CAR_LENGTH];
	for (int i = 0; i < _numberOfCar; i++)
	{
		do
			tempCar[i] = (rand() % (79 - MAX_CAR_LENGTH)) + 1;
		while (abs(tempTruck[i] - tempCar[i]) <= 10);
		for (int j = 0; j < MAX_CAR_LENGTH; j++)
		{
			_c[i][j].setX(tempCar[i] + j);
			_c[i][j].setY(2 + i);
			_c[i][j].setSpeed(1);
		}
	}
	_d = new Dinausor*[MAX_DINAUSOR];
	for (int i = 0; i < _numberOfDinausor; i++)
		_d[i] = new Dinausor[MAX_DINAUSOR_LENGTH];
	for (int i = 0; i < _numberOfDinausor; i++)
	{
		do
			tempDinausor[i] = (rand() % (79 - MAX_DINAUSOR_LENGTH)) + 1;
		while (abs(tempTruck[i] - tempDinausor[i]) <= 10 || abs(tempCar[i] - tempDinausor[i]) <= 10);
		for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
		{
			_d[i][j].setX(tempDinausor[i] + j);
			_d[i][j].setY(2 + i);
			_d[i][j].setSpeed(1);
		}
	}
	_b = new Bird*[MAX_BIRD];
	for (int i = 0; i < _numberOfBird; i++)
		_b[i] = new Bird[MAX_BIRD_LENGTH];
	for (int i = 0; i < _numberOfBird; i++)
	{
		do
			tempBird[i] = (rand() % (79 - MAX_BIRD_LENGTH)) + 1;
		while (abs(tempTruck[i] - tempBird[i]) <= 10 || abs(tempCar[i] - tempBird[i]) <= 10 || abs(tempDinausor[i] - tempBird[i]) <= 10);
		for (int j = 0; j < MAX_BIRD_LENGTH; j++)
		{
			_b[i][j].setX(tempBird[i] + j);
			_b[i][j].setY(2 + i);
			_b[i][j].setSpeed(1);
		}
	}
}

Game::~Game()
{
	delete _player;
	for (int i = 0; i < _numberOfTruck; i++)
		delete _t[i];
	for (int i = 0; i < _numberOfCar; i++)
		delete _c[i];
	for (int i = 0; i < _numberOfDinausor; i++)
		delete _d[i];
	for (int i = 0; i < _numberOfBird; i++)
		delete _b[i];
	delete[] _t;
	delete[] _c;
	delete[] _d;
	delete[] _b;
}

void Game::drawGame(int x, int y, int width, int height)
{
	int curPosX = 0, curPosY = 0;
	int i;
	char temp;
	clrscr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	goToXY(0, 0);
	temp = 201;
	cout << temp;
	goToXY(119, 0); 
	temp = 187;
	cout << temp;
	goToXY(0, 29); 
	temp = 200;
	cout << temp;
	goToXY(119, 29);
	temp = 188;
	cout << temp;
	for (i = 1; i < width; i++)
	{
		goToXY(i, 0);
		temp = 205;
		cout << temp;
		goToXY(i, height);
		temp = 205;
		cout << temp;
		if (i < 80)
		{
			goToXY(i, 20); 
			temp = 205;
			cout << temp;
			goToXY(i, 1);
			if (i % 2)
			{
				temp = 219;
				cout << temp;
			}
			else
			{
				temp = 177;
				cout << temp;
			}
		}
		if (i > 80)
		{
			goToXY(i, 12);
			temp = 205;
			cout << temp;
		}
	}
	for (i = y + 1; i < height + y; i++)
	{
		goToXY(x, i);
		temp = 186;
		cout << temp;
		goToXY(x + width, i);
		temp = 186;
		cout << temp;
		goToXY(80, i);
		temp = 186;
		cout << temp;
		if (i > 20)
		{
			goToXY(35, i);
			temp = 186;
			cout << temp;
			goToXY(58, i);
			temp = 186;
			cout << temp;
		}
	}
	goToXY(35, 20);
	temp = 203;
	cout << temp;
	goToXY(35, 29);
	temp = 202;
	cout << temp;
	goToXY(58, 20);
	temp = 203;
	cout << temp;
	goToXY(58, 29);
	temp = 202;
	cout << temp;
	goToXY(80, 0);
	temp = 203;
	cout << temp;
	goToXY(80, 29);
	temp = 202;
	cout << temp;
	goToXY(80, 20);
	temp = 185;
	cout << temp;
	goToXY(0, 20);
	temp = 204;
	cout << temp;
	goToXY(80, 12);
	temp = 204;
	cout << temp;
	goToXY(119, 12);
	temp = 185;
	cout << temp;
	drawInstruction();
	goToXY(curPosX, curPosY);
	if (_player->getLevel() != 0)
	{
		drawTruck();
		drawCar();
		drawDinausor();
		drawBird();
		drawTrafficLight();
		_player->drawPlayer();
	}
	goToXY(40, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 - _player->getLevel());
	cout << "Level: " << _player->getLevel() + 1;
	setRecord();
}

void Game::loadFile()
{
	char loadFile[255];
	goToXY(1, 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	puts("Input File's name: ");
	goToXY(1, 28);
	cin >> loadFile;
	FILE *f;
	fopen_s(&f, loadFile, "rb");
	if (f == NULL)
	{
		clrscr();
		resetGame();
		goToXY(1, 27);
		goToXY(45, 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "  File not found";
		goToXY(47, 14);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "New game will start" << endl;
		Sleep(1000);
		return;
	}
	int a = _numberOfTruck;
	int b = _numberOfCar;
	int c = _numberOfDinausor;
	int d = _numberOfBird;
	fread(&_numberOfTruck, sizeof(int), 1, f);
	fread(&_numberOfCar, sizeof(int), 1, f);
	fread(&_numberOfDinausor, sizeof(int), 1, f);
	fread(&_numberOfBird, sizeof(int), 1, f);
	for (int i = a; i < _numberOfTruck; i++)
		_t[i] = new Truck[MAX_TRUCK_LENGTH];
	for (int i = b; i < _numberOfCar; i++)
		_c[i] = new Car[MAX_CAR_LENGTH];
	for (int i = c; i < _numberOfDinausor; i++)
		_d[i] = new Dinausor[MAX_DINAUSOR_LENGTH];
	for (int i = d; i < _numberOfBird; i++)
		_b[i] = new Bird[MAX_BIRD_LENGTH];
	int temp[4];
	fread(&temp[0], sizeof(int), 1, f);
	fread(&temp[1], sizeof(int), 1, f);
	fread(&temp[2], sizeof(int), 1, f);
	fread(&temp[3], sizeof(int), 1, f);
	_player->setXY(temp[0],temp[1]);
	for (int i = 0; i < _numberOfTruck; i++)
		for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
			_t[i][j].setSpeed(temp[2]);
	for (int i = 0; i < _numberOfCar; i++)
		for (int j = 0; j < MAX_CAR_LENGTH; j++)
			_c[i][j].setSpeed(temp[2]);
	for (int i = 0; i < _numberOfDinausor; i++)
		for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
			_d[i][j].setSpeed(temp[2]);
	for (int i = 0; i < _numberOfBird; i++)
		for (int j = 0; j < MAX_BIRD_LENGTH; j++)
			_b[i][j].setSpeed(temp[2]);
	_player->setLevel(temp[3]);
	for (int i = 0; i < _numberOfTruck; i++)
		for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
		{
			int t[2];
			fread(&t[0], sizeof(int), 1, f);
			fread(&t[1], sizeof(int), 1, f);
			_t[i][j].setX(t[0]);
			_t[i][j].setY(t[1]);
		}
	for (int i = 0; i < _numberOfCar; i++)
		for (int j = 0; j < MAX_CAR_LENGTH; j++)
		{
			int c[2];
			fread(&c[0], sizeof(int), 1, f);
			fread(&c[1], sizeof(int), 1, f);
			_c[i][j].setX(c[0]);
			_c[i][j].setY(c[1]);
		}
	for (int i = 0; i < _numberOfDinausor; i++)
		for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
		{
			int d[2];
			fread(&d[0], sizeof(int), 1, f);
			fread(&d[1], sizeof(int), 1, f);
			_d[i][j].setX(d[0]);
			_d[i][j].setY(d[1]);
		}
	for (int i = 0; i < _numberOfBird; i++)
		for (int j = 0; j < MAX_BIRD_LENGTH; j++)
		{
			int b[2];
			fread(&b[0], sizeof(int), 1, f);
			fread(&b[1], sizeof(int), 1, f);
			_b[i][j].setX(b[0]);
			_b[i][j].setY(b[1]);
		}
	fclose(f);
}

void Game::saveFile()
{
	char saveFile[255];
	goToXY(1, 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Input File's name: " << endl;
	goToXY(1, 28);
	cin >> saveFile;
	FILE *f;
	fopen_s(&f, saveFile, "wb");
	fwrite(&_numberOfTruck, sizeof(int), 1, f);
	fwrite(&_numberOfCar, sizeof(int), 1, f);
	fwrite(&_numberOfDinausor, sizeof(int), 1, f);
	fwrite(&_numberOfBird, sizeof(int), 1, f);
	int temp = _player->getX();
	fwrite(&temp, sizeof(int), 1, f);
	temp = _player->getY();
	fwrite(&temp, sizeof(int), 1, f);
	temp = _t[0][0].getSpeed();
	fwrite(&temp, sizeof(int), 1, f);
	temp = _player->getLevel();
	fwrite(&temp, sizeof(int), 1, f);
	for (int i = 0; i < _numberOfTruck; i++)
		for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
		{
			temp = _t[i][j].getX();
			fwrite(&temp, sizeof(int), 1, f);
			temp = _t[i][j].getY();
			fwrite(&temp, sizeof(int), 1, f);
		}
	for (int i = 0; i < _numberOfCar; i++)
		for (int j = 0; j < MAX_CAR_LENGTH; j++)
		{
			temp = _c[i][j].getX();
			fwrite(&temp, sizeof(int), 1, f);
			temp = _c[i][j].getY();
			fwrite(&temp, sizeof(int), 1, f);
		}
	for (int i = 0; i < _numberOfDinausor; i++)
		for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
		{
			temp = _d[i][j].getX();
			fwrite(&temp, sizeof(int), 1, f);
			temp = _d[i][j].getY();
			fwrite(&temp, sizeof(int), 1, f);
		}
	for (int i = 0; i < _numberOfBird; i++)
		for (int j = 0; j < MAX_BIRD_LENGTH; j++)
		{
			temp = _b[i][j].getX();
			fwrite(&temp, sizeof(int), 1, f);
			temp = _b[i][j].getY();
			fwrite(&temp, sizeof(int), 1, f);
		}
	fclose(f);
	drawGame(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	drawMenu();
	_player->drawPlayer();
}

void Game::resetGame()
{
	clrscr();
	_numberOfTruck = 8;
	_numberOfCar = 8;
	_numberOfDinausor = 8;
	_numberOfBird = 8;
	_player->setXY(18, 19);
	_player->setLevel(0);
	for (int i = 0; i < _numberOfTruck; i++)
		for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
			_t[i][j].setSpeed(1);
	for (int i = 0; i < _numberOfCar; i++)
		for (int j = 0; j < MAX_CAR_LENGTH; j++)
			_c[i][j].setSpeed(1);
	for (int i = 0; i < _numberOfDinausor; i++)
		for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
			_d[i][j].setSpeed(1);
	for (int i = 0; i < _numberOfBird; i++)
		for (int j = 0; j < MAX_BIRD_LENGTH; j++)
			_b[i][j].setSpeed(1);
}

void Game::startGame()
{
	_beginTime = clock();
	drawGame(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	drawMenu();
	_player->drawPlayer();
	_player->setState(1);
}

void Game::exitGame(HANDLE t)
{
	clrscr();
	TerminateThread(t, 0);
}

void Game::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

void Game::processDead()
{
	char s[120];
	clrscr();
	ifstream file("graphDie.txt");
	for (int count = 0; count < 10; count++)
	{
		file.seekg(0);
		goToXY(0, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (int i = 1; i <= 17; i++)
		{
			file.getline(s, 120);
			puts(s);
		}
		Sleep(200);
	}
	_player->setState(0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	goToXY(45, 23);
	cout << "     Press R to restart game";
	goToXY(50, 25);
	cout << "Press Esc to exit game";
}

void Game::processWin(int T)
{
	char s[120];
	ifstream file("graphWon.txt");
	for (int count = 0; count < 10; count++)
	{
		file.seekg(0);
		clrscr();
		goToXY(0, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (int i = 1; i <= 16; i++)
		{
			file.getline(s, 120);
			puts(s);
		}
		Sleep(200);
		clrscr();
		goToXY(0, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (int i = 1; i <= 16; i++)
		{
			file.getline(s, 120);
			puts(s);
		}
		Sleep(200);
	}
	clrscr();
	_player->setState(0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	if (T >= 0)
	{
		goToXY(52, 19);
		cout << "Input Your Name";
		goToXY(52, 21);
		cin >> _top[T].name;
		ofstream file("top.txt");
		for (int i = 0; i < 10; i++)
			if (i % 2 == 0)
				file << _top[i / 2].name << endl;
			else
				file << _top[i / 2].t << endl;
		file.close();
	}
	goToXY(45, 23); 
	cout << "     Press R to restart game";
	goToXY(50, 25); 
	cout << "Press Ecs to exit game";
}

void Game::processFinish()
{
	if (_player->getLevel() == 4)
		processWin(isRecord(clock()));
	else
	{
		_player->setLevel(_player->getLevel() + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 - _player->getLevel());
		goToXY(40, 25);
		cout << "Level: " << _player->getLevel() + 1;
		int tempTruck[16];
		int tempCar[16];
		int tempDinausor[16];
		int tempBird[16];
		if (_numberOfTruck < MAX_TRUCK && _numberOfCar < MAX_CAR && _numberOfDinausor < MAX_DINAUSOR && _numberOfBird < MAX_BIRD)
		{
			for (int i = _numberOfTruck; i < _numberOfTruck + 4; i++)
				_t[i] = new Truck[MAX_TRUCK_LENGTH];
			for (int i = _numberOfTruck; i < _numberOfTruck + 4; i++)
			{
				tempTruck[i] = (rand() % (79 - MAX_TRUCK_LENGTH)) + 1;
				for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
				{
					_t[i][j].setX(tempTruck[i] + j);
					_t[i][j].setY(2 + i);
				}
			}
			for (int i = _numberOfCar; i < _numberOfCar + 4; i++)
				_c[i] = new Car[MAX_CAR_LENGTH];
			for (int i = _numberOfCar; i < _numberOfCar + 4; i++)
			{
				do
					tempCar[i] = (rand() % (79 - MAX_CAR_LENGTH)) + 1;
				while (abs(tempTruck[i] - tempCar[i]) <= 10);
				for (int j = 0; j < MAX_CAR_LENGTH; j++)
				{
					_c[i][j].setX(tempCar[i] + j);
					_c[i][j].setY(2 + i);
				}
			}
			for (int i = _numberOfDinausor; i < _numberOfDinausor + 4; i++)
				_d[i] = new Dinausor[MAX_DINAUSOR_LENGTH];
			for (int i = _numberOfDinausor; i < _numberOfDinausor + 4; i++)
			{
				do
					tempDinausor[i] = (rand() % (79 - MAX_DINAUSOR_LENGTH)) + 1;
				while (abs(tempTruck[i] - tempDinausor[i]) <= 10 || abs(tempCar[i] - tempDinausor[i]) <= 10);
				for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
				{
					_d[i][j].setX(tempDinausor[i] + j);
					_d[i][j].setY(2 + i);
				}
			}
			for (int i = _numberOfBird; i < _numberOfBird + 4; i++)
				_b[i] = new Bird[MAX_BIRD_LENGTH];
			for (int i = _numberOfBird; i < _numberOfBird + 4; i++)
			{
				do
					tempBird[i] = (rand() % (79 - MAX_BIRD_LENGTH)) + 1;
				while (abs(tempTruck[i] - tempBird[i]) <= 10 || abs(tempCar[i] - tempBird[i]) <= 10 || abs(tempDinausor[i] - tempBird[i]) <= 10);
				for (int j = 0; j < MAX_BIRD_LENGTH; j++)
				{
					_b[i][j].setX(tempBird[i] + j);
					_b[i][j].setY(2 + i);
				}
			}
			_numberOfTruck += 4;
			_numberOfCar += 4;
			_numberOfDinausor += 4;
			_numberOfBird += 4;
		}
		else
		{
			for (int i = 0; i < _numberOfTruck; i++)
				for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
				{
					int temp = _t[i][j].getSpeed();
					_t[i][j].setSpeed(temp + 1);
				}
			for (int i = 0; i < _numberOfCar; i++)
				for (int j = 0; j < MAX_CAR_LENGTH; j++)
				{
					int temp = _c[i][j].getSpeed();
					_c[i][j].setSpeed(temp + 1);
				}
			for (int i = 0; i < _numberOfDinausor; i++)
				for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
				{
					int temp = _d[i][j].getSpeed();
					_d[i][j].setSpeed(temp + 1);
				}
			for (int i = 0; i < _numberOfBird; i++)
				for (int j = 0; j < MAX_BIRD_LENGTH; j++)
				{
					int temp = _b[i][j].getSpeed();
					_b[i][j].setSpeed(temp + 1);
				}
		}
		_player->setXY(18, 19);
		_player->drawPlayer();
	}
}

void Game::create()
{
	_player->setLevel(_player->getLevel() + 1);
	int tempTruck[16];
	int tempCar[16];
	int tempDinausor[16];
	int tempBird[16];
	if (_numberOfTruck < MAX_TRUCK && _numberOfCar < MAX_CAR && _numberOfDinausor < MAX_DINAUSOR && _numberOfBird < MAX_BIRD)
	{
		for (int i = _numberOfTruck; i < _numberOfTruck + 4; i++)
			_t[i] = new Truck[MAX_TRUCK_LENGTH];
		for (int i = _numberOfTruck; i < _numberOfTruck + 4; i++)
		{
			tempTruck[i] = (rand() % (79 - MAX_TRUCK_LENGTH)) + 1;
			for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
			{
				_t[i][j].setX(tempTruck[i] + j);
				_t[i][j].setY(2 + i);
			}
		}
		for (int i = _numberOfCar; i < _numberOfCar + 4; i++)
			_c[i] = new Car[MAX_CAR_LENGTH];
		for (int i = _numberOfCar; i < _numberOfCar + 4; i++)
		{
			do
				tempCar[i] = (rand() % (79 - MAX_CAR_LENGTH)) + 1;
			while (abs(tempTruck[i] - tempCar[i]) <= 10);
			for (int j = 0; j < MAX_CAR_LENGTH; j++)
			{
				_c[i][j].setX(tempCar[i] + j);
				_c[i][j].setY(2 + i);
			}
		}
		for (int i = _numberOfDinausor; i < _numberOfDinausor + 4; i++)
			_d[i] = new Dinausor[MAX_DINAUSOR_LENGTH];
		for (int i = _numberOfDinausor; i < _numberOfDinausor + 4; i++)
		{
			do
				tempDinausor[i] = (rand() % (79 - MAX_DINAUSOR_LENGTH)) + 1;
			while (abs(tempTruck[i] - tempDinausor[i]) <= 10 || abs(tempCar[i] - tempDinausor[i]) <= 10);
			for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
			{
				_d[i][j].setX(tempDinausor[i] + j);
				_d[i][j].setY(2 + i);
			}
		}
		for (int i = _numberOfBird; i < _numberOfBird + 4; i++)
			_b[i] = new Bird[MAX_BIRD_LENGTH];
		for (int i = _numberOfBird; i < _numberOfBird + 4; i++)
		{
			do
				tempBird[i] = (rand() % (79 - MAX_BIRD_LENGTH)) + 1;
			while (abs(tempTruck[i] - tempBird[i]) <= 10 || abs(tempCar[i] - tempBird[i]) <= 10 || abs(tempDinausor[i] - tempBird[i]) <= 10);
			for (int j = 0; j < MAX_BIRD_LENGTH; j++)
			{
				_b[i][j].setX(tempBird[i] + j);
				_b[i][j].setY(2 + i);
			}
		}
		_numberOfTruck += 4;
		_numberOfCar += 4;
		_numberOfDinausor += 4;
		_numberOfBird += 4;
	}
	else
	{
		for (int i = 0; i < _numberOfTruck; i++)
			for (int j = 0; j < MAX_TRUCK_LENGTH; j++)
			{
				int temp = _t[i][j].getSpeed();
				_t[i][j].setSpeed(temp + 1);
			}
		for (int i = 0; i < _numberOfCar; i++)
			for (int j = 0; j < MAX_CAR_LENGTH; j++)
			{
				int temp = _c[i][j].getSpeed();
				_c[i][j].setSpeed(temp + 1);
			}
		for (int i = 0; i < _numberOfDinausor; i++)
			for (int j = 0; j < MAX_DINAUSOR_LENGTH; j++)
			{
				int temp = _d[i][j].getSpeed();
				_d[i][j].setSpeed(temp + 1);
			}
		for (int i = 0; i < _numberOfBird; i++)
			for (int j = 0; j < MAX_BIRD_LENGTH; j++)
			{
				int temp = _b[i][j].getSpeed();
				_b[i][j].setSpeed(temp + 1);
			}
	}
	_player->setXY(18, 19);
}

void Game::drawTruck()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	for (int i = 0; i < _numberOfTruck; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		_t[i][0].drawHeadTruck();
		for (int j = 1; j < MAX_TRUCK_LENGTH; j++)
		{
			if (stopMark(i) == 1)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			_t[i][j].drawBodyTruck();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
	for (int i = 1; i < _numberOfTruck; i+=2)
	{
		for (int j = 0; j < MAX_TRUCK_LENGTH - 1; j++)
		{
			if (stopMark(i) == 1)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				_t[i][j].drawBodyTruck();
		}
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		_t[i][MAX_TRUCK_LENGTH - 1].drawHeadTruck();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::drawCar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < _numberOfCar; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		_c[i][0].drawHeadCar();
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		_c[i][MAX_CAR_LENGTH - 1].drawHeadCar();
		for (int j = 1; j < MAX_CAR_LENGTH - 1; j++)
		{
			if (stopMark(i) == 1)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			_c[i][j].drawBodyCar();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	}
	for (int i = 1; i < _numberOfCar; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		_c[i][0].drawHeadCar();
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		_c[i][MAX_CAR_LENGTH - 1].drawHeadCar();
		for (int j = 1; j < MAX_CAR_LENGTH - 1; j++)
		{
			if (stopMark(i) == 1)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			_c[i][j].drawBodyCar();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::drawDinausor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int i = 0; i < _numberOfDinausor; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][0].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][1].drawAnimal(219);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][2].drawAnimal(220);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][MAX_DINAUSOR_LENGTH - 1].drawAnimal(' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}
	for (int i = 1; i < _numberOfDinausor; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][0].drawAnimal(220);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][1].drawAnimal(219);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][2].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		_d[i][MAX_DINAUSOR_LENGTH - 1].drawAnimal(' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::drawBird()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	for (int i = 0; i < _numberOfBird; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][0].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][1].drawAnimal(254);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][2].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][MAX_BIRD_LENGTH - 1].drawAnimal(' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	for (int i = 1; i < _numberOfBird; i += 2)
	{
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][0].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][1].drawAnimal(254);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][2].drawAnimal(223);
		if (stopMark(i) == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		_b[i][MAX_BIRD_LENGTH - 1].drawAnimal(' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool Game::isImpact(int t)
{
	if (t == 1 || t == 19) return 0;
	for (int i = 0; i < MAX_TRUCK_LENGTH; i++)
		if (t - 2 >= 0 && t - 2 < _numberOfTruck)
			if (_player->getX() == _t[t - 2][i].getX() && _player->getY() == _t[t - 2][i].getY())
				return 1;
	for (int i = 0; i < MAX_CAR_LENGTH; i++)
		if (t - 2 >= 0 && t - 2 < _numberOfCar)
			if (_player->getX() == _c[t - 2][i].getX() && _player->getY() == _c[t - 2][i].getY())
				return 1;
	for (int i = 0; i < MAX_DINAUSOR_LENGTH - 1; i++)
		if (t - 2 >= 0 && t - 2 < _numberOfDinausor)
			if (_player->getX() == _d[t - 2][i].getX() && _player->getY() == _d[t - 2][i].getY())
				return 1;
	for (int i = 0; i < MAX_BIRD_LENGTH - 1; i++)
		if (t - 2 >= 0 && t - 2 < _numberOfBird)
			if (_player->getX() == _b[t - 2][i].getX() && _player->getY() == _b[t - 2][i].getY())
				return 1;
	if (t - 2 >= 0 && t - 2 < _numberOfDinausor)
		if (_player->getX() == _d[t - 2][MAX_DINAUSOR_LENGTH - 1].getX() && _player->getY() == _d[t - 2][MAX_DINAUSOR_LENGTH - 1].getY())
			_player->drawPlayer();
	if (t - 2 >= 0 && t - 2 < _numberOfDinausor)
		if (_player->getX() == _b[t - 2][MAX_BIRD_LENGTH - 1].getX() && _player->getY() == _b[t - 2][MAX_BIRD_LENGTH - 1].getY())
			_player->drawPlayer();
	return 0;
}

void Game::moveTruck()
{
	int count;
	for (int i = 0; i < _numberOfTruck; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = MAX_TRUCK_LENGTH - 1; j > 0; j--)
					_t[i][j] = _t[i][j - 1];
				int temp = _t[i][0].getX() - 1;
				if (temp == 0)
					_t[i][0].setX(79);
				else
					_t[i][0].setX(temp);
			} while (count < _t[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfTruck; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = 0; j < MAX_TRUCK_LENGTH - 1; j++)
					_t[i][j] = _t[i][j + 1];
				int temp = _t[i][MAX_TRUCK_LENGTH - 1].getX() + 1;
				if (temp == 80)
					_t[i][MAX_TRUCK_LENGTH - 1].setX(1);
				else
					_t[i][MAX_TRUCK_LENGTH - 1].setX(temp);
			} while (count < _t[0][0].getSpeed());
		}
}

void Game::moveCar()
{
	int count;
	for (int i = 0; i < _numberOfCar; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = MAX_CAR_LENGTH - 1; j > 0; j--)
					_c[i][j] = _c[i][j - 1];
				int temp = _c[i][0].getX() - 1;
				if (temp == 0)
					_c[i][0].setX(79);
				else
					_c[i][0].setX(temp);
			} while (count < _c[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfCar; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = 0; j < MAX_CAR_LENGTH - 1; j++)
					_c[i][j] = _c[i][j + 1];
				int temp = _c[i][MAX_CAR_LENGTH - 1].getX() + 1;
				if (temp == 80)
					_c[i][MAX_CAR_LENGTH - 1].setX(1);
				else
					_c[i][MAX_CAR_LENGTH - 1].setX(temp);
			} while (count < _c[0][0].getSpeed());
		}
}

void Game::moveDinausor()
{
	int count;
	for (int i = 0; i < _numberOfDinausor; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = MAX_DINAUSOR_LENGTH - 1; j > 0; j--)
					_d[i][j] = _d[i][j - 1];
				int temp = _d[i][0].getX() - 1;
				if (temp == 0)
					_d[i][0].setX(79);
				else
					_d[i][0].setX(temp);
			} while (count < _d[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfDinausor; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = 0; j < MAX_DINAUSOR_LENGTH - 1; j++)
					_d[i][j] = _d[i][j + 1];
				int temp = _d[i][MAX_DINAUSOR_LENGTH - 1].getX() + 1;
				if (temp == 80)
					_d[i][MAX_DINAUSOR_LENGTH - 1].setX(1);
				else
					_d[i][MAX_DINAUSOR_LENGTH - 1].setX(temp);
			} while (count < _d[0][0].getSpeed());
		}
}

void Game::moveBird()
{
	int count;
	for (int i = 0; i < _numberOfBird; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = MAX_BIRD_LENGTH - 1; j > 0; j--)
					_b[i][j] = _b[i][j - 1];
				int temp = _b[i][0].getX() - 1;
				if (temp == 0)
					_b[i][0].setX(79);
				else
					_b[i][0].setX(temp);
			} while (count < _b[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfBird; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				count++;
				for (int j = 0; j < MAX_BIRD_LENGTH - 1; j++)
					_b[i][j] = _b[i][j + 1];
				int temp = _b[i][MAX_BIRD_LENGTH - 1].getX() + 1;
				if (temp == 80)
					_b[i][MAX_BIRD_LENGTH - 1].setX(1);
				else
					_b[i][MAX_BIRD_LENGTH - 1].setX(temp);
			} while (count < _b[0][0].getSpeed());
		}
}

void Game::eraseTruck()
{
	int count;
	for (int i = 0; i < _numberOfTruck; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _t[i][MAX_TRUCK_LENGTH - 1 - count].getX();
				int y = _t[i][MAX_TRUCK_LENGTH - 1 - count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _t[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfTruck; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _t[i][count].getX();
				int y = _t[i][count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _t[0][0].getSpeed());
		}
}

void Game::eraseCar()
{
	int count;
	for (int i = 0; i < _numberOfCar; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _c[i][MAX_CAR_LENGTH - 1 - count].getX();
				int y = _c[i][MAX_CAR_LENGTH - 1 - count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _c[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfCar; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _c[i][count].getX();
				int y = _c[i][count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _c[0][0].getSpeed());
		}
}

void Game::eraseDinausor()
{
	int count;
	for (int i = 0; i < _numberOfDinausor; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _d[i][MAX_DINAUSOR_LENGTH - 1 - count].getX();
				int y = _d[i][MAX_DINAUSOR_LENGTH - 1 - count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _d[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfDinausor; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _d[i][count].getX();
				int y = _d[i][count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _d[0][0].getSpeed());
		}
}

void Game::eraseBird()
{
	int count;
	for (int i = 0; i < _numberOfBird; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _b[i][MAX_BIRD_LENGTH - 1 - count].getX();
				int y = _b[i][MAX_BIRD_LENGTH - 1 - count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _b[0][0].getSpeed());
		}
	for (int i = 1; i < _numberOfBird; i += 2)
		if (stopMark(i) == 1)
		{
			count = 0;
			do
			{
				int x = _b[i][count].getX();
				int y = _b[i][count].getY();
				goToXY(x, y);
				cout << " ";
				count++;
			} while (count < _b[0][0].getSpeed());
		}
}

bool Game::stopMark(int i)
{
	int a = (_time - _beginTime) % 10000;
	int b = (_player->getLevel() + 1) * 1000;
	if (a < 2000)
		for (int j = 0; j < (_player->getLevel() + 1) * 2; j++)
			_stop[j] = rand() % _numberOfBird;
	bool check = 0;
	for (int j = 0; j < (_player->getLevel() + 1) * 2; j++)
		if (i == _stop[j])
		{
			check = 1;
			break;
		}
	if (check == 0)
		return 1;
	if (a > 2000 && a < 2000 + b)
		return 0;
	return 1;
}

void Game::drawMenu()
{
	char s[40] = "";
	ifstream file("menu.txt");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 1; i < 15; i++)
	{
		goToXY(85, i + 11);
		file.getline(s, 40);
		if (i > 1)
			puts(s);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	file.close();
}

void Game::drawInstruction()
{
	char s[80];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	ifstream file("instruction.txt");
	for (int i = 1; i < 7; i++)
	{
		file.getline(s, 33);
		goToXY(2, 21 + i); puts(s);
	}
	file.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::drawImpact()
{
	cout << "\a";
	char s[] = { '.','.', 178 };
	int i, j, dem = 0;
	while (dem < 12)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (i = _player->getX() - 1; i <= _player->getX() + 1; i++)
			for (j = _player->getY() - 1; j <= _player->getY() + 1; j++)
			{
				goToXY(i, j);
				cout << s[dem % 3];
			}
		dem++;
		Sleep(300);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::drawIcon()
{
	char s[50];
	ifstream file("icon.txt");
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (int i = 1; i <= 10; i++)
		{
			file.getline(s, 50);
			goToXY(85, i);
			puts(s);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	file.close();
}

void Game::drawStart()
{
	char s[120];
	goToXY(45, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "      1: New Game";
	goToXY(47, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "    2: Load Game";
	goToXY(49, 26);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "  3: Setting";
	goToXY(51, 28);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Esc: Exit";
	ifstream file("graphStart.txt");
	while (!_kbhit())
	{
		goToXY(0, 7);
		file.seekg(0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 16);
		for (int i = 1; i <= 12; i++)
		{
			file.getline(s, 120);
			puts(s);
		}
		Sleep(200);
	}
	file.close();
}

void Game::drawLoading()
{
	clrscr();
	char temp;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	goToXY(55, 11);
	cout << "Loading...";
	for (int i = 40; i < 80; i++)
	{
		goToXY(i, 13);
		temp = 177;
		cout << temp;
		Sleep(50);
	}
}

void Game::drawTrafficLight()
{
	for (int i = 2; i < _numberOfBird + 2; i++)
		if (stopMark(i - 2) == 1)
		{
			goToXY(81, i);
			char temp = 254;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << temp;
			goToXY(82, i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << temp;
		}
		else
		{
			goToXY(81, i);
			char temp = 254;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << temp;
			goToXY(82, i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << temp;
		}
}

void Game::setRecord()
{
	ifstream file("top.txt");
	for (int i = 0; i < 10; i++)
		if (i % 2 == 0)
			file >> _top[i / 2].name;
		else
			file >> _top[i / 2].t;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	goToXY(65, 22); cout << " Best ";
	for (int i = 0; i < 5; i++)
	{
		goToXY(62, 23 + i); 
		cout << _top[i].name;
		goToXY(70, 23 + i); 
		cout << _top[i].t << 's';
	}
	file.close();
}

int Game::isRecord(clock_t t)
{
	int pos = -1;
	clock_t temp = (t - _beginTime) / 1000;
	for (int i = 0; i < 5; i++)
		if (temp < _top[i].t)
		{
			pos = i;
			break;
		}
	if (pos >= 0)
	{
		for (int i = 4; i > pos; i--)
		{
			for (int j = 0; j <= strlen(_top[i - 1].name); j++)
				_top[i].name[j] = _top[i - 1].name[j];
			_top[i].t = _top[i - 1].t;
		}
		_top[pos].t = temp;
	}
	return pos;
}