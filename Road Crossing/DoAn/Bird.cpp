#include"Bird.h"

void Bird::birdSinging()
{
	PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
}

void Bird::birdDoNotSinging()
{
	PlaySound(NULL, NULL, SND_ASYNC);
}