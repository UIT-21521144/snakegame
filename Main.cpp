#include<iostream>
#include<Windows.h>
#include"mylib.h"

using namespace std;

void ShowConsoleCursor(bool);
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void ShowScrollbar(BOOL Show);
int MenuStart();
void ve_tuong();
void Name();
void gameover();
int endMenu();
int dieuKien(int x, int y);
void Move(int z, int k[], int h[], int CheDo);
void viTriGoc(int x[],int y[]);
void viTriGoc(int x[],int y[]);
void veRan(int x[], int y[]);
int Random(int n);
void Moi(int ToaDox[], int ToaDoy[], int *n, int *m);
void them(int ToaDox[], int ToaDoy[]);
void Diem(int *diem);
void reset(int &x);

#define TOP 2
#define LEFT 5
#define RIGHT 105
#define BOT 26
#define MAX 2156

int sl = 3;

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

int MenuStart(){
	char a, b, c, d ,e, f;
	b = 205;
	for(int i =41; i < 60; i++){
		gotoXY(i, 10);
		cout <<  b;
		gotoXY(i, 20);
		cout << b;
	}
	a = 186;
	for(int i =11; i < 20; i++){
		gotoXY(40, i);
		cout <<  a;
		gotoXY(60, i);
		cout << a;
	}
	c = 200;
	gotoXY(40, 20); cout << c;
	d = 187;
	gotoXY(60, 10); cout << d;
	e = 188;
	gotoXY(60,20); cout << e;
	f = 201;
	gotoXY(40,10) ; cout << f;
	gotoXY(46, 11);system("Color 2");
	cout << "MENU";
	gotoXY(41,12);cout << "- 1. Easy.";
	gotoXY(41,13);cout << "- 2. Medium.";
	gotoXY(41,14);cout << "- 3. Hard.";
	int t;
	gotoXY(41,15); cout<< "Your choice: ";
	gotoXY(55,15); cin >> t;
	if (t == 1){
		return 1;
	}else if (t == 2){
		return 2;
	}else if ( t == 3){
		return 3;
	}else {
		system("cls");
		gotoXY(41,12);cout << "Chon lai. ";
		Sleep(500);
		MenuStart();
	}
}

void viTriGoc(int x[], int y[]) {
	int a = 50; int b = 15;
	for (int i = 0; i <= sl; i++) {
		x[i] = a; y[i] = b;
		a--;
	}
}

void gameover(int x[],int y[]){
	char kitu = 5;
	gotoXY(x[0], y[0]); cout << kitu;
	for(int i = 1; i <sl; i++){
		gotoXY(x[i],y[i]); cout << " ";
	}
	gotoXY(45, 11);system("Color 4");
	gotoXY(21, 8) ; cout << " * * *";
	gotoXY(9, 7) ; cout << "* * * * * * * * *";
	gotoXY(9, 6) ; cout << " * * * * * * * * ";
	gotoXY(9, 5); cout << "  * * * * * * *";
	gotoXY(8, 8); cout << "* * *"; 
	gotoXY(7, 9); cout << "* * *"; 
	gotoXY(7, 10); cout << "* * *"; 
	gotoXY(8, 11); cout << "* * *"; 
	gotoXY(9, 12); cout << "* * *"; 
	gotoXY(10, 13) ; cout << "* * * * * * * * *";
	gotoXY(10, 14) ; cout << " * * * * * * * * ";
	gotoXY(10, 15); cout << "  * * * * * * *";
	gotoXY(19, 10) ; cout << "* * * * * *";
	gotoXY(19, 11) ; cout << "* * * * * *";
	gotoXY(22, 12) ; cout << "* * *";
	gotoXY(38, 5) ; cout << "* * *";
	gotoXY(37, 6) ; cout << "* * * *";
	gotoXY(36, 7) ; cout << "* * * * *";
	gotoXY(35, 8) ; cout << "* * * * * *";
	gotoXY(34, 9) ; cout << "* * *   * * *";
	gotoXY(33, 10) ; cout << "* * *     * * *";
	gotoXY(32, 11) ; cout << "* * * * * * * * *";
	gotoXY(31, 12) ; cout << "* * * * * * * * * *";
	gotoXY(30, 13) ; cout << "* * *           * * *";
	gotoXY(29, 14) ; cout << "* * *             * * *";
	gotoXY(28, 15) ; cout << "* * *               * * *";
	gotoXY(54, 5) ; cout << "* * *                 * * *";
	gotoXY(54, 6) ; cout << "* * * *             * * * *";
	gotoXY(54, 7) ; cout << "* * * * *         * * * * * ";
	gotoXY(54, 8) ; cout << "* * * * * *     * * * * * *";
	gotoXY(54, 9) ; cout << "* * *   * * * * *     * * *";
	gotoXY(54, 10) ; cout <<"* * *    * * * *      * * *";
	gotoXY(54, 11) ; cout <<"* * *     * * *       * * *";
	gotoXY(54, 12) ; cout <<"* * *                 * * *";
	gotoXY(54, 13) ; cout <<"* * *                 * * *";
	gotoXY(54, 14) ; cout <<"* * *                 * * *";
	gotoXY(54, 15) ; cout <<"* * *                 * * *";
	gotoXY(83, 5) ; cout <<"* * * * * * *";
	gotoXY(83, 6) ; cout <<"* * * * * * *";
	gotoXY(83, 7) ; cout <<"* * *";
	gotoXY(83, 8) ; cout <<"* * *";
	gotoXY(83, 9) ; cout <<"* * * * * * *";
	gotoXY(83, 10) ; cout <<"* * * * * * *";
	gotoXY(83, 11) ; cout <<"* * * * * * *";
	gotoXY(83, 12) ; cout <<"* * *";
	gotoXY(83, 13) ; cout <<"* * *";
	gotoXY(83, 14) ; cout <<"* * * * * * *";
	gotoXY(83, 15) ; cout <<"* * * * * * *";
	gotoXY(30,18); cout << "* * * * ";
	gotoXY(29,19);cout <<  "* * * * * ";
	gotoXY(28,20);cout << "* *     * *";
	gotoXY(27,21); cout<<"* *       * *";
	gotoXY(27,22); cout<<"* *       * *";
	gotoXY(28,23);cout << "* *     * *";
	gotoXY(29,24);cout <<  "* * * * * ";
	gotoXY(30,25); cout << "* * * *";
	gotoXY(40,18); cout << "* *             * *";
	gotoXY(41,19); cout << "* *           * *";
	gotoXY(42,20); cout << "* *         * *";
	gotoXY(43,21); cout << "* *       * *";
	gotoXY(44,22); cout << "* *     * *";
	gotoXY(45,23); cout << "* *   * *";
	gotoXY(46,24); cout << "* * * *";
	gotoXY(47,25); cout << "* * *";
	gotoXY(60,18); cout << "* * * * *";
	gotoXY(60,19); cout << "* * * * *";
	gotoXY(60,20); cout << "* *";
	gotoXY(60,21); cout << "* * * * *";
	gotoXY(60,22); cout << "* * * * *";
	gotoXY(60,23); cout << "* *";
	gotoXY(60,24); cout << "* * * * *";
	gotoXY(60,25); cout << "* * * * *";
	gotoXY(71,18); cout << "* * * *";
	gotoXY(71,19); cout << "* * * * *";
	gotoXY(71,20); cout << "* *   * *";
	gotoXY(71,21); cout << "* * * * *";
	gotoXY(71,22); cout << "* * *";
	gotoXY(71,23); cout << "* * * *";
	gotoXY(71,24); cout << "* *   * *";
	gotoXY(71,25); cout << "* *     * *";
}
int endMenu(){
	system("cls");
	char a, b, c, d ,e, f;
	b = 205;
	for(int i =46; i < 70; i++){
		gotoXY(i, 9);
		cout <<  b;
		gotoXY(i, 20);
		cout << b;
	}
	a = 186;
	for(int i =10; i < 20; i++){
		gotoXY(45, i);
		cout <<  a;
		gotoXY(70, i);
		cout << a;
	}
	c = 200;
	gotoXY(45, 20); cout << c;
	d = 187;
	gotoXY(70, 9); cout << d;
	e = 188;
	gotoXY(70,20); cout << e;
	f = 201;
	gotoXY(45,9) ; cout << f;
	gotoXY(53,10); cout << "GAME OVER";
	gotoXY(46, 12); cout << "1. EXIT";
	gotoXY(46, 13); cout << "2. REPLAY";
	int x;
	gotoXY(46, 14);cout << "Your Choice: ";
	gotoXY(60,14); cin >> x;
	if( x == 1 ){
		return 1;
	} 
	else if(x == 2) {
		reset(sl);
		return 2;
	}
	else {
		gotoXY(46,15) ;cout << "Chon sai.";
		Sleep(2000);
		gotoXY(46,15) ;cout << "         ";
		endMenu();
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

void Move(int z, int k[], int h[], int CheDo) {
	char khn = 205;
	char khd = 186;
	int diem = 0;
	gotoXY(105,29); cout << "SCORE : " << diem;
	int n, m;
	Moi(k, h, &n, &m);
	int xcu, ycu , xcucheck , ycucheck;
	int xcu2 = sl, ycu2 = sl ;
	char a = 002;
	int Check = 0;
	int Checkcu = 0;
	while (true) {
		int ktrax, ktray;
		ktrax = k[0]; ktray = h[0];
		gotoXY(k[sl], h[sl]); cout << " ";
		if (CheDo == 1){
			if(dieuKien(ktrax,ktray, k, h) != 5 ) break;
		}else if(CheDo == 2){
			if(dieuKien(ktrax,ktray,k,h) == 0) break;
		}
		gotoXY(k[0],h[0]);
		cout << a;
		if (_kbhit())
		{
			char dieukhien = _getch();
			if (dieukhien == -32 )
			{
				dieukhien = _getch();
				if (dieukhien == 72) // len
					Check = 1;
				else if (dieukhien == 80) // xuong
					Check = 0;
				else if (dieukhien == 77) // phai
					Check = 3;
				else if (dieukhien == 75)
					Check = 2;
			}
			
		}
		// Khong Duoc Di Nguoc
		xcu = k[0]; ycu = h[0];
		xcucheck = k[1]; ycucheck = h[1];
		//Check di nguoc
		if ( Check == 0 and ycucheck == h[0] + 1) Check = 1;
		else if ( Check == 1 and ycucheck == h[0] - 1) Check = 0;
		else if ( Check == 2 and xcucheck == k[0] - 1) Check = 3;
		else if ( Check == 3 and xcucheck == k[0] + 1) Check = 2;
		if(CheDo == 2){
			if(k[0] == 6 && Check == 2) k[0] = 104;
			else if(k[0] == 104 && Check == 3) k[0] = 6;
			else if(h[0] == 3 && Check == 1) h[0] = 25;
			else if(h[0] == 25 && Check == 0) h[0] = 3;
		}
		//Move
		if (Check == 0) h[0]++;
		else if (Check == 1) h[0]--;
		else if (Check == 2) k[0]--;
		else if (Check == 3) k[0]++;
		// Thay Doi Vi Tri cua Than
		for(int i = 1; i <= sl; i++){
			xcu2 =k[i]; ycu2 = h[i];
			k[i] = xcu;h[i] = ycu;
			xcu = xcu2;ycu = ycu2;
		}
		for(int i = 0 ; i <sl ; i++){
			if (i == 0){
				gotoXY(k[i], h[i]); cout << a;
			}else {
				gotoXY(k[i], h[i]); cout << "o";
			}
		}
		if (k[0] == n && h[0] == m){
			diem++;
			them( k , h);
			Moi(k,h,&n,&m);
			Diem(&diem);
		}
		Sleep(z);
	}
	gameover(k, h);
}

void Play(){
	int n;
	int ToaDox[MAX], ToaDoy[MAX];
	Name();
	string a;
	gotoXY(52,14); cout << "Name: "; cin >>a;
	system("cls");
	int CheDo = MenuXin();
	int x;
	system("cls");
	x = MenuStart();
	system("cls");
	ShowConsoleCursor(false);
	SetWindowSize(200,100);
	SetScreenBufferSize(200,100);
	DisableResizeWindow();
	DisableCtrButton(1,1,1);
	ShowScrollbar(0);
	ve_tuong();
	gotoXY (1,1); cout << "PLAYER: " << a;
	int z;
	if(x == 1) z = 1000;
	if(x == 2) z = 200;
	if(x == 3) z = 100;
	viTriGoc(ToaDox, ToaDoy);
	veRan(ToaDox, ToaDoy);
	Move( z, ToaDox, ToaDoy, CheDo);
	Sleep(2000);
	int k = endMenu();
	
	if (k == 1){
		system("cls");
		gotoXY(50,12); cout << "SEE YOU AGAIN!";
	} else {
		system("cls");
		Play();
	}
}


void reset(int &x )
{
	x = 3;
}

int main(){
	Play();
	return 0;
}
