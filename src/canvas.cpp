#include <canvas.h>

namespace drawer {

const void* pen_base::get_native_pen() const {
	return nullptr;
}

bool canvas_base::draw(const pen_base&, const figure&) {
	return false;
}

bool canvas_base::draw(const pen_base&, const rect&) {
	return false;
}

bool canvas_base::draw(const pen_base&, const circle&) {
	return false;
}

bool canvas_base::draw(const pen_base& p, const polygon& r) {
	return false;
}

bool canvas_base::draw(const pen_base& p, const triangle& t) {
	return draw(p, t.as_polygon());
}

const dimension& canvas_base::get_size() const {
	return size;
}

canvas_base::canvas_base(const dimension& size) : size(size) {}

}