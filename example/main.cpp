#include <screen.h>
#include <canvas.h>
#include <figure.h>
#include <iostream>

using namespace drawer;
using namespace drawer::winapi;

int main() {
	window win;
	win.show([](canvas& c){
		pen p(color(255, 0, 0));
		c.draw(p, rect(0, 0, 100, 200));
		std::cout << "on_paint()" << std::endl;
	});

	return drawer::winapi::app_loop();
}