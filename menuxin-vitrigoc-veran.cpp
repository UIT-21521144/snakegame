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