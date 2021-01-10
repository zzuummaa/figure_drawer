//
// Created by Stepan on 10.01.2021.
//

#ifndef FIGURE_DRAWER_CANVAS_H
#define FIGURE_DRAWER_CANVAS_H

#include <figure.h>
#include <screen.h>
#include <gdiplus.h>

namespace drawer::winapi {
	class canvas;

	class pen {
		friend class canvas;
		Gdiplus::Pen native_pen;
	public:
		explicit pen(const color& c) : native_pen(Gdiplus::Color(c.get_r(), c.get_g(), c.get_b())) {}
	};

	class canvas {
		PAINTSTRUCT ps;
		HWND hWnd;
		HDC hdc;
		Gdiplus::Graphics graphics;
	public:
		explicit canvas(const window& w) : ps(), hWnd(w.hWnd), hdc(BeginPaint(w.hWnd, &ps)), graphics(hdc) {}

		canvas(const canvas&) = delete;
		canvas(canvas&&) = delete;

		virtual ~canvas() {
			if (hWnd != nullptr) EndPaint(hWnd, &ps);
		}

		template<typename F, std::enable_if_t<std::is_base_of_v<figure, F>, bool> = true>
		bool draw(const pen& p, const figure&) {
			return false;
		}

		bool draw(const pen& p, const rect& r) {
			return graphics.DrawRectangle(&p.native_pen, r.get_x(), r.get_y(), r.get_width(), r.get_height()) == Gdiplus::Ok;
		}
	};
}

#endif //FIGURE_DRAWER_CANVAS_H
