#include <canvas.h>

namespace drawer::winapi {

pen::pen(const color& c) : native_pen(Gdiplus::Color(c.get_r(), c.get_g(), c.get_b())) {}

const void* pen::get_native_pen() const {
	return &native_pen;
}

canvas::canvas(const window& w) : canvas_base(w.size), ps(), hWnd(w.hWnd), hdc(BeginPaint(w.hWnd, &ps)), graphics(hdc) {}

canvas::~canvas() {
	if (hWnd != nullptr) EndPaint(hWnd, &ps);
}

bool canvas::draw(const pen_base& pb, const figure& f) {
	return canvas_base::draw(pb, f);
}

bool canvas::draw(const pen_base& p, const rect& r) {
	return graphics.DrawRectangle(
			reinterpret_cast<const Gdiplus::Pen*>(p.get_native_pen()),
			r.get_x(), r.get_y(), r.get_width(), r.get_height()
	) == Gdiplus::Ok;
}

bool canvas::draw(const pen_base& p, const circle& r) {
	return graphics.DrawEllipse(
			reinterpret_cast<const Gdiplus::Pen*>(p.get_native_pen()),
			r.get_x(), r.get_y(), r.get_r(), r.get_r()
	) == Gdiplus::Ok;
}

bool canvas::draw(const pen_base& p, const polygon& r) {
	return graphics.DrawPolygon(
			reinterpret_cast<const Gdiplus::Pen*>(p.get_native_pen()),
			reinterpret_cast<const Gdiplus::Point*>(r.begin().base()), r.size()
	) == Gdiplus::Ok;
}

}
