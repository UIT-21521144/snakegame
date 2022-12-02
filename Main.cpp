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

void Name(){
	char a, b, c, d ,e, f;
	b = 205;
	for(int i =51; i < 64; i++){
		gotoXY(i, 11);
		cout <<  b;
		gotoXY(i, 15);
		cout << b;
	}
	a = 186;
	for(int i =12; i < 15; i++){
		gotoXY(50, i);
		cout <<  a;
		gotoXY(64, i);
		cout << a;
	}
	c = 200;
	gotoXY(50, 15); cout << c;
	d = 187;
	gotoXY(64, 11); cout << d;
	e = 188;
	gotoXY(64,15); cout << e;
	f = 201;
	gotoXY(50,11) ; cout << f;
	gotoXY(56,12); cout << "NAME";
}

int MenuXin() {
	char a, b, c, d, e, f;
	b = 205;
	for (int i = 41; i < 60; i++) {
		gotoXY(i, 10);
		cout << b;
		gotoXY(i, 20);
		cout << b;
	}
	a = 186;
	for (int i = 11; i < 20; i++) {
		gotoXY(40, i);
		cout << a;
		gotoXY(60, i);
		cout << a;
	}
	c = 200;
	gotoXY(40, 20); cout << c;
	d = 187;
	gotoXY(60, 10); cout << d;
	e = 188;
	gotoXY(60, 20); cout << e;
	f = 201;
	gotoXY(40, 10); cout << f;
	gotoXY(46, 11); system("Color 2");
	cout << "MENU";
	gotoXY(41, 12); cout << "- 1. Truyen Thong.";
	gotoXY(41, 13); cout << "- 2. Hien Dai.";
	int t;
	gotoXY(41, 15); cout << "Your choice: ";
	gotoXY(55, 15); cin >> t;
	if (t == 1) {
		return 1;
	}
	else if (t == 2) {
		return 2;
	}
	else {
		system("cls");
		gotoXY(41, 12); cout << "Chon lai. ";
		Sleep(500);
		MenuXin();
	}
}

void viTriGoc(int x[], int y[]) {
	int a = 50; int b = 15;
	for (int i = 0; i <= sl; i++) {
		x[i] = a; y[i] = b;
		a--;
	}
}

void veRan(int x[], int y[]) {
	char a = 002;
	for (int i = 0; i < sl; i++) {
		if (i == 0) {
			gotoXY(x[i], y[i]); cout << a;
		}
		else {
			gotoXY(x[i], y[i]); cout << "o";
		}
	}
}
int dieuKien(int x, int y,int ToaDox[],int ToaDoy[]){
	if ( x == 5 ){
		return 1;
	}else if ( x == 105 ){
		return 2;
	}
	else if (  y == 2 ){
		return 3;
	}else if (  y == 26){
		return 4;
	}
	for(int i = 1; i < sl; i++){
		if(ToaDox[0] == ToaDox[i] && ToaDoy[0] == ToaDoy[i] ) return 0;
	}
	return 5;
}
void Diem(int *diem){
	gotoXY(105,29); cout << "SCORE : " << *diem;
}
void them(int ToaDox[], int ToaDoy[]){
	int x, y;
	x = ToaDox[sl];
	y = ToaDoy[sl];
	sl++;
	ToaDox[sl-1] = x;
	ToaDoy[sl-1] = y;
}

int Random(int n)
{
   return rand()%(n+1);
}

void Moi(int ToaDox[], int ToaDoy[], int *n, int *m){
	int x = Random(98) + 6;
	int y = Random(22) + 3;
	for(int i = 0; i < sl; i++){
		if(x == ToaDox[i] && y == ToaDoy[i]){
			Moi(ToaDox,ToaDoy,n,m);
		}
	}
	*n = x; *m = y;
	gotoXY(x,y);
	cout << "*";
}


void reset(int &x )
{
	x = 3;
}

int main(){
	ShowConsoleCursor(false);
	SetWindowSize(200,100);
	SetScreenBufferSize(200,100);
	DisableResizeWindow();
	DisableCtrButton(1,1,1);
	ShowScrollbar(0);
	ve_tuong(); cout <<"\n";
	MenuXin();
	viTriGoc(x,y);
	veRan(x,y);
	return 0;
}
