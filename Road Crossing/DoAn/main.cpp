#include"Game.h"

int moving;
Game *p = new Game;
People *player = p->getPlayer();
Bird *b;
bool sound = 1;

void subThread()
{
	bool check = 1;
	p->setBeginTime(clock());
	while (1)
	{
		if (player->getState() == 1)
		{
			p->setTime(clock());
			if ((p->getTime() - p->getBeginTime()) / 1000 == 0 && check == 1 && sound == 1)
			{
				b->birdSinging();
				check = 0;
			}
			if ((p->getTime() - p->getBeginTime()) / 1000 % 66 == 0 && sound == 1 && (p->getTime() - p->getBeginTime()) / 1000)
			{
				delete b;
				b = new Bird;
				b->birdSinging();
			}
			goToXY(40, 23);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 - player->getLevel());
			cout << "Time: " << (p->getTime() - p->getBeginTime()) / 1000 << ',' << (p->getTime() - p->getBeginTime()) % 1000 << 's';
			if (moving == 'W')
				p->up();
			if (moving == 'A')
				p->left();
			if (moving == 'D')
				p->right();
			if (moving == 'S')
				p->down();
			moving = ' ';
			p->eraseTruck();
			p->eraseCar();
			p->eraseDinausor();
			p->eraseBird();
			p->moveTruck();
			p->moveCar();
			p->moveDinausor();
			p->moveBird();
			p->drawTruck();
			p->drawCar();
			p->drawDinausor();
			p->drawBird();
			p->drawTrafficLight();
			if (p->isImpact(player->getY()))
			{
				if (sound == 1)
				{
					b->birdDoNotSinging();
					check = 1;
				}
				p->drawImpact();
				p->processDead();
			}
			else
			{
				if (player->getY() == 1)
				{
					if (player->getLevel() == 4 && sound == 1)
						b->birdDoNotSinging();
					p->processFinish();
				}
				if (player->getState() == 1)
					p->drawIcon();
			}
			Sleep(50);
		}
	}
}

int main()
{
	int temp;
	int prev = 0;
	int count = 0;
	int countSetting = 0;
	bool check = 0;
	clrscr();
	fixConsoleWindow();
	p->drawStart();
	srand(time(NULL));
	while (1)
	{
		for (int i = 0; i < countSetting; i++)
			temp = toupper('0');
		count++;
		temp = toupper(_getch());
		if (temp == 0 && count % 2 == 0)
			continue;
		if (temp == 27)
			return 0;
		if (temp == '1')
		{
			p->drawLoading();
			p->startGame();
			break;
		}
		if (temp == '2')
		{
			p->loadFile();
			p->drawLoading();
			p->startGame();
			break;
		}
		if (temp == '3')
		{
			countSetting++;
			int setting;
			clrscr();
			goToXY(45, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "Current Level: " << player->getLevel() + 1 << endl;
			goToXY(30, 13);
			cout << "Enter the level you want: (The highest level is 5) ";
			cin >> setting;
			setting--;
			if (setting >= 5)
				setting = 4;
			p->resetGame();
			for (int i = 0; i < setting; i++)
				p->create();
			clrscr();
			goToXY(45, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			if (sound == 1)
				cout << "Sound: ON";
			else
				cout << "Sound: OFF";
			goToXY(45, 13);
			cout << "Press 1 to on sound";
			goToXY(45, 14);
			cout << "Press 2 to off sound" << endl;
			_getch();
			setting = toupper(_getch());
			if (setting == '1')
				sound = 1;
			if (setting == '2')
				sound = 0;
			_getch();
			clrscr();
			p->drawStart();
			continue;
		}
	}
	count = 0;
	thread t1(subThread);
	while (1)
	{
		count++;
		temp = toupper(_getch());
		if (temp == 'P')
		{
			p->pauseGame(t1.native_handle());
			if (sound == 1)
				b->birdDoNotSinging();
		}
		if (player->getState() == 1)
		{
			if (temp == 27)
			{
				p->exitGame(t1.native_handle());
				t1.join();
				return 0;
			}
			else
				if (temp == 'P')
					p->pauseGame(t1.native_handle());
				else
				{
					if (prev == 'P')
						check = 1;
					if (check == 1 && count % 2 == 0)
					{
						check = 0;
						if (sound == 1)
							b->birdSinging();
					}
					ResumeThread((HANDLE)t1.native_handle());
					if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S')
						moving = temp;
				}
			if (temp == 'L')
			{
				if (sound == 1)
					b->birdDoNotSinging();
				p->pauseGame(t1.native_handle());
				p->saveFile();
				if (sound == 1)
					b->birdSinging();
			}
			else
				if (temp == 'T')
				{
					if (sound == 1)
						b->birdDoNotSinging();
					player->setState(0);
					p->pauseGame(t1.native_handle());
					p->loadFile();
					clrscr();
					p->drawLoading();
					p->startGame();
				}
				else
					if (temp == 'R')
					{
						player->setState(0);
						p->resetGame();
						p->startGame();
					}
		}
		else
			if (temp == 'R')
			{
				player->setState(0);
				p->resetGame();
				p->startGame();
			}
			else
			{
				p->exitGame(t1.native_handle());
				t1.join();
				return 0;
			}
		prev = temp;
	}
	return 0;
}