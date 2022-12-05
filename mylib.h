
#include <stdio.h>
#include <conio.h>
#include <ctime> // time real
#include<Windows.h> // https://www.quora.com/What-is-the-use-of-include-windows-h-in-C-programming-language

#define KEY_NONE -1
// toa do x
int WhereX(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
// toa do y
int WhereY(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//dich den toa do x, y
void gotoXY(int x, int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//mauchu
void SetColor(WORD color){
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//an chuot
void ShowCur(bool CursorVisibility){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility};
	SetConsoleCursorInfo(handle, &cursor);
}
//tra ve phim dung nguoi bam
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}