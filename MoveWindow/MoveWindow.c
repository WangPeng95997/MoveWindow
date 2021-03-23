#include <Windows.h>
#define TIME 60
const int move[] = { 1, 1, 2, 2, 3, 3, 4, 4, 3, 3, 2, 2, 1, 1,
					-1,-1,-2,-2,-3,-3,-4,-4,-3,-3,-2,-2,-1,-1 };
const int nCount = sizeof(move) / sizeof(void*);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	HWND hwnd;
	RECT rekt;

	for (int i = 0, t = 0, delay = 0;;)
	{
		for (i = 0;; i = (nCount <= ++i) ? 0 : i)
		{
			if ((hwnd = GetForegroundWindow()) == NULL)
				break;

			for (t = 0, delay = TIME / abs(move[i]); t < abs(move[i]); t++)
			{
				GetWindowRect(hwnd, &rekt);
				MoveWindow(hwnd, rekt.left, rekt.top + (move[i] < 0 ? -1 : 1), rekt.right - rekt.left, rekt.bottom - rekt.top, FALSE);
				Sleep(delay);
			}
		}
		Sleep(TIME);
	}

	return 0;
}