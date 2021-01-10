#include <canvas.h>
#include <screen.h>


namespace drawer {

bool window_base::show(const window_base::on_paint_function& fun) {
	if (is_showing) return false;
	on_paint = fun;
	is_showing = true;
	return true;
}

window_base::window_base() : is_showing(false) {}

} // namespace drawer