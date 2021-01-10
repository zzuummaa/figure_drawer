//
// Created by Stepan on 10.01.2021.
//

#ifndef FIGURE_DRAWER_CANVAS_H
#define FIGURE_DRAWER_CANVAS_H

#include <figure.h>
#include <screen.h>
#include <gdiplus.h>

namespace drawer {
	class pen_base {
	public:
		virtual const void* get_native_pen() const = 0;
	};

	class canvas_base {
	public:
		virtual bool draw(const pen_base&, const figure&) {
			return false;
		}
	};
}

namespace drawer::winapi {
	class canvas;

	class pen final: public pen_base {
		friend class canvas;
		Gdiplus::Pen native_pen;
	public:
		explicit pen(const color& c) : native_pen(Gdiplus::Color(c.get_r(), c.get_g(), c.get_b())) {}
		const void* get_native_pen() const override { return &native_pen; }
	};

	class canvas final : public canvas_base {
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

		bool draw(const pen_base& pb, const figure& f) override {
			return canvas_base::draw(pb, f);
		}

		bool draw(const pen& p, const rect& r) {
			return graphics.DrawRectangle(
				reinterpret_cast<const Gdiplus::Pen*>(p.get_native_pen()),
				r.get_x(), r.get_y(), r.get_width(), r.get_height()
			) == Gdiplus::Ok;
		}
	};
}

#endif //FIGURE_DRAWER_CANVAS_H
