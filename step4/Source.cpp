#include <windows.h>
#include<d3dx9.h>
#include<tchar.h>
#include<dinput.h>

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szstr, INT iCmdshow)
{
	MSG msg;
	static char szAppName[] = "ORESAMA";
	WNDCLASSEX wndclass;


	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = wndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);
	//	ウィンドウ生成
	HWND hInsT = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, NULL, NULL, hInst, NULL);

	ShowWindow(hInsT, SW_SHOW);
	UpdateWindow(hInsT);
	

	timeBeginPeriod(1);
	//今の時間をtimeに保存。
	DWORD time = timeGetTime();
	DWORD prevtime = 0;

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			Sleep(1);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			
			}


			prevtime = time;

		}
		timeEndPeriod(1);

	}
	



LRESULT CALLBACK wndProc(HWND hInst, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}

	return DefWindowProc(hInst, iMsg, wParam, lParam);
}

