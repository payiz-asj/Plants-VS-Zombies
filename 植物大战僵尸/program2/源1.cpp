//#pragma comment(lib,"user32")
//#pragma comment(lib,"gdi32")
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <tchar.h>
//HWND WINAPI GetConsoleWindow();
//void HideTheCursor() {
//	CONSOLE_CURSOR_INFO cciCursor;
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
//		cciCursor.bVisible = FALSE;
//		SetConsoleCursorInfo(hStdOut, &cciCursor);
//	}
//}
//void ShowTheCursor() {
//	CONSOLE_CURSOR_INFO cciCursor;
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
//		cciCursor.bVisible = TRUE;
//		SetConsoleCursorInfo(hStdOut, &cciCursor);
//	}
//}
//int main() {
//	HWND  hwnd;
//	HDC   hdc;
//	HFONT hfont;
//	system(" CHCP 936");
//	system("color F0");
//	system("cls");
//	HideTheCursor();
//	hwnd = GetConsoleWindow();
//	hdc = GetDC(hwnd);
//	//  hfont = CreateFont(48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "华文楷体");
//	hfont = CreateFont(48, 0, 0, 0, 0, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, _T("华文楷体"));
//	SelectObject(hdc, hfont);
//	TextOut(hdc, 10, 10, _T("地球人都知道！"), 14);
//	MoveToEx(hdc, 5, 5, NULL);
//	LineTo(hdc, 300, 5);
//	LineTo(hdc, 300, 60);
//	LineTo(hdc, 5, 60);
//	LineTo(hdc, 5, 5);
//	DeleteObject(hfont);
//	ReleaseDC(hwnd, hdc);
//	getchar();
//	system("color 07");
//	system("cls");
//	ShowTheCursor();
//	return 0;
//}


//
//#pragma comment(lib,"user32")
//#pragma comment(lib,"gdi32")
//#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
//#include <tchar.h>
//HWND WINAPI GetConsoleWindow();
//void HideTheCursor() {
//	CONSOLE_CURSOR_INFO cciCursor;
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
//		cciCursor.bVisible = FALSE;
//		SetConsoleCursorInfo(hStdOut, &cciCursor);
//	}
//}
//void ShowTheCursor() {
//	CONSOLE_CURSOR_INFO cciCursor;
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
//		cciCursor.bVisible = TRUE;
//		SetConsoleCursorInfo(hStdOut, &cciCursor);
//	}
//}
//int main() {
//	HWND  hwnd;
//	HDC   hdc;
//	HFONT hfont;
//	HBITMAP hbm;
//	HDC hdcBits;
//	BITMAP bm;
//
//	system("color F0");
//	system("cls");
//	HideTheCursor();
//	hwnd = GetConsoleWindow();
//	hdc = GetDC(hwnd);
//	hbm = LoadImage(0, _T("C:\\Windows\\Soap Bubbles.bmp"), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
//	if (hbm) {
//		hdcBits = CreateCompatibleDC(hdc);
//		GetObject(hbm, sizeof(BITMAP), &bm);
//		SelectObject(hdcBits, hbm);
//		BitBlt(hdc, 200, 10, bm.bmWidth, bm.bmHeight, hdcBits, 0, 0, SRCCOPY);
//		DeleteDC(hdcBits);
//		DeleteObject(hbm);
//	}
//	hfont = CreateFont(24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("华文楷体"));
//	SelectObject(hdc, hfont);
//	SetTextColor(hdc, RGB(255, 255, 255));
//	SetBkMode(hdc, TRANSPARENT);
//	TextOut(hdc, 210, 30, _T("这个背景是泡泡"), 14);
//	DeleteObject(hfont);
//	ReleaseDC(hwnd, hdc);
//	getch();
//	system("color 07");
//	system("cls");
//	ShowTheCursor();
//	return 0;
//}
//
//