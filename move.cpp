#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib> 

#define MAX 100

using namespace std;


int toa_dox[MAX] = { 0 };
int toa_doy = { 0 };
//size ran

void play()
{
	ve_tuong();
	khoi_tao_ran();
	int x = toa_dox[0];
	int y = toa_doy[0];
	int check = 2;
	while (true)
	{
		gotoXY(toa_dox[snake.size], toa_doy[snake.size]);
		cout << " ";
		Drawsnake();
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32);
			{
				c = _getch();
				if (c==72)
				{
					check = 1;
				}
				else if (c == 80) 
				{
					check = 0;
				}
				else if (c == 75)
				{
					check = 3;
				}
				else if (c == 77)
				{
					check = 2;
				}
			}
		}
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x==;
		}
		else if (check == 3)
		{
			x--;
		}
		move(x, y);
		Sleep(100);
	}
}

void move(int x, int y)
{
	for (int i = snake.size; i > 0; i--)
	{
		toa_dox[i] = toa_dox[i - 1];
		toa_doy[i] = toa_doy[i - 1];
	}
	toa_dox[0] = x;
	toa_doy[0] = y;
}