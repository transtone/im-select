#include "stdafx.h"
#include <Windows.h>
#include <cstdlib>

using namespace std;

int getInputMethod() {
	HWND hwnd = GetForegroundWindow();
	if (hwnd) {
		DWORD threadID = GetWindowThreadProcessId(hwnd, NULL);
		HKL currentLayout = GetKeyboardLayout(threadID);
		unsigned int x = (unsigned int)currentLayout & 0x0000FFFF;
		return ((int)x);
	}
	return 0;
}

void selectEn() {
	HWND hwnd = GetForegroundWindow();
	HWND hwndIME = ImmGetDefaultIMEWnd(hwnd);
	if (hwndIME) {
		// LRESULT result = SendMessage(hwndIME, 0x283, 0x001, 0);
		// printf("%d\n", result);

		keybd_event(VK_SHIFT, 0, 0, 0);
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	}
}

void switchInputMethod(int locale) {
	HWND hwnd = GetForegroundWindow();
	LPARAM currentLayout = ((LPARAM)locale);
	PostMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, currentLayout);
	if (locale == 1033) {
		selectEn();
	}
}

int main(int argc, char** argv)
{
	if (argc == 1) {
		selectEn();
		int imID = getInputMethod();
		printf("%d\n", imID);
	} else {
		int locale = atoi(argv[1]);
		switchInputMethod(locale);
	}
	return 0;
}

