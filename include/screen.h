#ifndef FIGURE_DRAWER_WINAPI_H
#define FIGURE_DRAWER_WINAPI_H

#include <figure.h>
#include <functional>
#include <Windows.h>
#include <gdiplus.h>

namespace drawer {
	class canvas_base;

	class window_base {
	public:
		typedef std::function<void(canvas_base&)> on_paint_function;

		window_base();

		virtual bool show(const on_paint_function& fun);

	protected:
		bool is_showing;
		on_paint_function on_paint;
	};
}

namespace drawer::winapi {

	class window : public window_base {
		HWND hWnd;
		WNDCLASS wndClass;
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;

	public:
		friend class canvas;

		window();
		window(const window&) = delete;
		window(window&&) = default;

		~window() = default;

		bool show(const on_paint_function& fun) override;

		LRESULT CALLBACK handle_message(UINT message, WPARAM wParam, LPARAM lParam);
	};

	int app_loop();
}

#endif //FIGURE_DRAWER_WINAPI_H
