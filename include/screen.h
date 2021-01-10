#ifndef FIGURE_DRAWER_WINAPI_H
#define FIGURE_DRAWER_WINAPI_H

#include <figure.h>
#include <functional>
#include <Windows.h>
#include <gdiplus.h>

namespace drawer::winapi {
	class canvas;

	class window {
	public:
		typedef std::function<void(canvas&)> on_paint_function;

	private:
		HWND hWnd;
		WNDCLASS wndClass;
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;

		on_paint_function on_paint;

	public:
		friend class canvas;

		window() = default;
		window(const window&) = delete;
		window(window&&) = default;

		~window() = default;

		bool show(const on_paint_function& fun);

		LRESULT CALLBACK handle_message(UINT message, WPARAM wParam, LPARAM lParam);

	};

	int app_loop();
}

#endif //FIGURE_DRAWER_WINAPI_H
