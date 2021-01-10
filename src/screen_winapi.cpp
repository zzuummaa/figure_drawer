#include <screen.h>
#include <canvas.h>
#include <gdiplus.h>

using namespace Gdiplus;

namespace drawer::winapi {

int app_loop() {
	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT wnd_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	auto *w = reinterpret_cast<window*>(GetWindowLong(hWnd, GWLP_USERDATA));
	if (w != nullptr) {
		return w->handle_message(message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool window::show(const on_paint_function& fun) {
	on_paint = fun;
	HINSTANCE hInstance = GetModuleHandle(NULL);

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style          = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc    = wnd_proc;
	wndClass.cbClsExtra     = 0;
	wndClass.cbWndExtra     = 0;
	wndClass.hInstance      = hInstance;
	wndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName   = NULL;
	wndClass.lpszClassName  = TEXT("GettingStarted");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
			TEXT("GettingStarted"),   // window class name
			TEXT("Getting Started"),  // window caption
			WS_OVERLAPPEDWINDOW,      // window style
			CW_USEDEFAULT,            // initial x position
			CW_USEDEFAULT,            // initial y position
			CW_USEDEFAULT,            // initial x size
			CW_USEDEFAULT,            // initial y size
			NULL,                     // parent window handle
			NULL,                     // window menu handle
			hInstance,                // program instance handle
			NULL);                    // creation parameters

	SetWindowLong(hWnd, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	return true;
}

LRESULT window::handle_message(UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message)
	{
		case WM_PAINT: {
			if (on_paint) {
				canvas c(*this);
				on_paint(c);
			}
			return 0;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

} // namespace drawer::winapi
