// Not for skid

#include <windows.h> 
#include <math.h>

int main() {
	HDC hdc = GetDC(NULL); 
	const int w = GetSystemMetrics(SM_CXSCREEN);
	const int h = GetSystemMetrics(SM_CYSCREEN);
	
	while (1) {
		hdc = GetDC(NULL);
		int radius = 100;
		
		int randx = rand() % w;
		int randy = rand() % h;
		
		for (int i = 0; i < w + h; i++) {
			int x = radius + i * cos(i + radius * 3) + randx;
			int y = radius + i * sin(i + radius * 3) + randy;
			HBRUSH hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	    	        SelectObject(hdc, hBrush);
	    	
			BitBlt(hdc, x, y, 20, 20, hdc, 0, 0, PATINVERT);
			DeleteObject(hBrush);
			Sleep(10);
		}
		ReleaseDC(NULL, hdc);
	}
	return 0;
}
