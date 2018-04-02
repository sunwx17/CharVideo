#include "console.h"

void setFont(int x, int y) {
	PCONSOLE_FONT_INFOEX fontex = new _CONSOLE_FONT_INFOEX();
	fontex->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, fontex);
	fontex->dwFontSize.X = x;
	fontex->dwFontSize.Y = y;
	WCHAR font[LF_FACESIZE] = L"·ÂËÎ";
	for (int i = 0; i < LF_FACESIZE; i++) fontex->FaceName[i] = font[i];
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, fontex);
	delete fontex;
}

void setWindow(int x, int y) {
	HWND hwnd = GetForegroundWindow();
	char cmd[28];
	sprintf_s(cmd, "mode con cols=%d lines=%d", x, y);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 1280 , 960, NULL);
	system(cmd);
	//COORD setbuffer = GetLargestConsoleWindowSize(hwnd);
	//SetConsoleScreenBufferSize(hwnd, setbuffer);
}

void FullScreen() {//À´×ÔÍøÂç
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	char setting[30];
	sprintf_s(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, x + 300, y + 300, NULL);
	MoveWindow(hwnd, -10, -40, x + 300, y + 300, 1);
}

void resetCursor() {
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
