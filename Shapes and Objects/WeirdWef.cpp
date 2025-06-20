#include <windows.h> 
#include <math.h>
#define M_PI   3.14159265358979323846264338327950288 

HRGN CreateRgn(int x, int y, int size) {
	POINT points[6];
	double angle = 2 * M_PI / 6;
	for (int i = 0; i < 6; i++) {
		points[i].x = x + (int)(size * sin(i * angle));
		points[i].y = y + (int)(size * tan(i * angle));
	}
	points[6] = points[0];
	return CreatePolygonRgn(points, 6, WINDING);
}

VOID WINAPI ci(int x, int y, int w, int h) {
	HDC hdc = GetDC(0);
	HRGN hrgn = CreateRgn(x, y, w / 2);
	SelectClipRgn(hdc, hrgn);
	BitBlt(hdc, x - w / 2, y - h / 2, w, h, hdc, x - w / 2, y - h / 2, NOTSRCCOPY);
	DeleteObject(hrgn);
	ReleaseDC(0, hdc);
}

INT main() {
	RECT rect;
	GetWindowRect(GetDesktopWindow(), &rect);
	int w = rect.right - rect.left - 500;
	int h = rect.bottom - rect.top - 500;
	for (int t = 0;; t++) {
		const int size = 1000;
		int x = rand() % (w + size) - size / 2;
		int y = rand() % (h + size) - size / 2;
		for (int i = 0; i < size; i += 100) {
			ci(x - i / 50, y - i / 50, i, i);
			Sleep(10);
		}
	}
}