#include "Simple_window.h"

int main()
{
	Button_window window { Point {0,0}, 800, 600, "Chapter 16" };

	window.show();
	return Fl::run();
}

