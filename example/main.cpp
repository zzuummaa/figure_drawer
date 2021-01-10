#include <screen.h>
#include <canvas.h>
#include <figure.h>
#include <iostream>
#include <cassert>

using namespace drawer;
using namespace drawer::winapi;

int main() {
	window win;
	win.show([](canvas& c){
		pen p(color(255, 0, 0));
		assert(c.draw(p, rect(100, 100, 200, 300)));
		assert(!c.draw(p, figure()));
		std::cout << "on_paint()" << std::endl;
	});

	return drawer::winapi::app_loop();
}