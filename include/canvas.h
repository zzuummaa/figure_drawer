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
		virtual const void* get_native_pen() const;
	};

	class canvas_base {
	protected:
		dimension size;
	public:
		canvas_base(const dimension& size);

		const dimension& get_size() const;

		virtual bool draw(const pen_base&, const figure&);

		virtual bool draw(const pen_base&, const rect&);

		virtual bool draw(const pen_base&, const circle&);

		virtual bool draw(const pen_base& p, const polygon& r);

		virtual bool draw(const pen_base& p, const triangle& t);
	};
}

namespace drawer::winapi {
	class pen final: public pen_base {
		Gdiplus::Pen native_pen;
	public:
		explicit pen(const color& c);
		const void* get_native_pen() const override;
	};

	class canvas final : public canvas_base {
		PAINTSTRUCT ps;
		HWND hWnd;
		HDC hdc;
		Gdiplus::Graphics graphics;
	public:
		explicit canvas(const window& w);

		canvas(const canvas&) = delete;
		canvas(canvas&&) = delete;

		virtual ~canvas();

		bool draw(const pen_base& pb, const figure& f) override;

		bool draw(const pen_base& p, const rect& r) override;

		bool draw(const pen_base& p, const circle& r) override;

		bool draw(const pen_base& p, const polygon& r) override;
	};
}

#endif //FIGURE_DRAWER_CANVAS_H
