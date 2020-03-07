#include "funkcje.h"

void czysc_buffor(char buffor[2000])
{
	for (int i = 0; i < 2000; i++)
	{
		buffor[i] = '/0';
	}
}