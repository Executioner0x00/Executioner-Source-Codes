// Not for skid

#include <windows.h> 

int main() { 
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);
	
	while (1) {
		HDC hdc = GetDC(0);
		POINT cursor;
		GetCursorPos(&cursor);

		Pie(hdc, cursor.x + 50, cursor.y + 50, cursor.x - 50, cursor.y - 50, 30, 30, rand() % w, rand() % h);
		ReleaseDC(0, hdc);
		Sleep(10);
	}
}