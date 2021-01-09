#ifndef FIGURE_DRAWER_WINAPI_H
#define FIGURE_DRAWER_WINAPI_H

#include <Windows.h>
#include <gdiplus.h>
#include <figure.h>
#include <vector>

namespace drawer::winapi {
	class canvas {
		PAINTSTRUCT ps;
		HWND hWnd;
		HDC hdc;
	public:
		canvas() : ps(), hWnd(nullptr), hdc(nullptr) {}

		explicit canvas(HWND hWnd) : ps(), hWnd(hWnd), hdc(BeginPaint(hWnd, &ps)) {}

		canvas(const canvas&) = delete;

		virtual ~canvas() {
			if (hWnd != nullptr) EndPaint(hWnd, &ps);
		}

		template<typename F, std::enable_if_t<std::is_base_of_v<figure, F>, bool> = true>
		bool draw(figure) {
			return false;
		}

		bool draw(rect r);
	};

	LRESULT CALLBACK wnd_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	class window {
		HWND hWnd;

		WNDCLASS wndClass;

		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;

		void on_paint(canvas& c);

	public:
		static canvas get_canvas(HWND hWnd);

		friend int app_loop(std::vector<window>&);

		window() = default;
		window(const window&) = delete;
		window(window&&) = default;

		~window() = default;

		bool show();

		canvas get_canvas();

		LRESULT CALLBACK handle_message(UINT message, WPARAM wParam, LPARAM lParam);
	};

	int app_loop(std::vector<window>&);
}

#endif //FIGURE_DRAWER_WINAPI_H
