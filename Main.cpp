#include<iostream>
#include<Windows.h>
#include"mylib.h"

using namespace std;

void ShowConsoleCursor(bool showFlag)// an con tro chuot
{
	HANDLE out =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void ve_tuong(){
	char a, b, c, d ,e, f;
	b = 205;
	for(int i =6; i < 105; i++){
		gotoXY(i, 2);
		cout <<  b;
		gotoXY(i, 26);
		cout << b;
	}
	a = 186;
	for(int i =3; i < 26; i++){
		gotoXY(5, i);
		cout <<  a;
		gotoXY(105, i);
		cout << a;
	}
	c = 200;
	gotoXY(5, 26); cout << c;
	d = 187;
	gotoXY(105, 2); cout << d;
	e = 188;
	gotoXY(105,26); cout << e;
	f = 201;
	gotoXY(5,2) ; cout << f;
}

int main(){
	ShowConsoleCursor(false);
	SetWindowSize(200,100);
	SetScreenBufferSize(200,100);
	DisableResizeWindow();
	DisableCtrButton(1,1,1);
	ShowScrollbar(0);
	ve_tuong(); cout <<"\n";
	return 0;
}
