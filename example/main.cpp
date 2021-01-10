#include <screen.h>
#include <canvas.h>
#include <figure.h>
#include <cassert>

using namespace drawer;
using namespace drawer::winapi;

int main() {
	window win1;

	assert(
		win1.show([](canvas_base& c){
			pen red(color(255, 0, 0));
			assert(c.draw(red, rect(100, 100, 200, 300)));
			assert(c.draw(red, rect(150, 200, 250, 350)));

			pen green(color(0, 255, 0));
			assert(c.draw(green, rect(450, 100, 550, 200)));
			assert(c.draw(green, circle(450, 300, 200)));

			assert(!c.draw(red, figure()));
		})
	);

	assert(!win1.show(window_base::on_paint_function()));

	window win2;

	assert(
		win2.show([](canvas_base& c){
			pen blue(color(0, 0, 255));
			assert(c.draw(blue, rect(100, 100, 200, 300)));
			assert(c.draw(blue, triangle(150, 150, 300, 200, 150, 250)));
		})
	);

	return drawer::winapi::app_loop();
}