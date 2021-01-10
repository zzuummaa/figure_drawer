# Figure drawer

Library for drawing figures.

## Build with Mingw

```cmd
git clone https://github.com/zzuummaa/figure_drawer.git
cd figure_drawer
mkdir build
cd build
cmake -G "CodeBlocks - MinGW Makefiles" ..
make -j6
```

## Example

After build you can ran example:

```cmd
figure_drawer_example.exe
```

Simple complete example:

```CPP
#include <screen.h>
#include <canvas.h>
#include <figure.h>

// Namespace contains platform independent parts
using namespace drawer;

// Namespace with WinAPI specified things: GUI windows, native canvas library binding
using namespace drawer::winapi;

int main() {
    window w;
    
    // Show window and draw figures via lambda
    w.show([](canvas_base& c){
        // Create pen with red color
        pen red(color(255, 0, 0));
        
        // Draw rectangle. Function return false if function unimplemented for this
        // platform or native library fail.
        c.draw(red, rect(100, 100, 200, 300));
    });
	
    // Handle events of all window objects. It's platform specified function
    return app_loop();
}
```