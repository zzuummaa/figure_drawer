#include <screen.h>

int main() {
	std::vector<drawer::winapi::window> windows;
	windows.emplace_back();
	windows.back().show();
	return drawer::winapi::app_loop(windows);
}