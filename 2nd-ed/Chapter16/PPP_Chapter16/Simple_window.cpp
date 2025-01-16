
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"

//------------------------------------------------------------------------------

//Simple_window::Simple_window(Point xy, int w, int h, const string& title) 
//	: Window { xy, w, h, title }
//	, next_button { Point {x_max() - 70, 0}, 70, 20, "Next", cb_next }
//	, button_pushed { false }
//{
//	attach(next_button);
//}

Simple_window::Simple_window(Point xy, int w, int h, const string& title)
	: Window { xy, w, h, title }
	, next_button { Point{x_max() - 70, 0}, 70, 20, "Next", 
	[](Address, Address pw) { reference_to<Simple_window>(pw).next(); } }
	, button_pushed { false }
{
	attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
	show();
	button_pushed = false;
#if 1
	// Simpler handler
	while (!button_pushed) Fl::wait();
	Fl::redraw();
#else
	// To handle the case where the user presses the X button in the window frame
	// to kill the application, change the condition to 0 to enable this branch.
	Fl::run();
#endif
	return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
	reference_to<Simple_window>(pw).next();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
	button_pushed = true;
	hide();
}

//My_window::My_window(Point xy, int w, int h, const string& title)
//	: Simple_window(xy, w, h, title)
//	, quit_button(Point(x_max() - 70, y_max() - 20), 70, 20, "quit", 
//		[](Address, Address pw) { cout << "quit btn clicked" << endl; })
//{
//	attach(quit_button);
//}

My_window::My_window(Point xy, int w, int h, const string& title)
	: Simple_window(xy, w, h, title)
	, quit_button(Point(x_max() - 70, y_max() - 20), 70, 20, "quit", cb_quit)
{
	attach(quit_button);
}

Button_window::Button_window(Point xy, int w, int h, const string& title)
	: My_window(xy, w, h, title)
	, menu1 { Point {0, 0}, 100, 40, Menu::Kind::horizontal, "Menu 1" }
	, menu2 { Point {0, 40}, 100, 40, Menu::Kind::horizontal, "Menu 2" }
	, menu3 { Point {0, 80}, 100, 40, Menu::Kind::horizontal, "Menu 3" }
	, menu4 { Point {0, 120}, 100, 40, Menu::Kind::horizontal, "Menu 4" }
	, xy_out { Point {0, 160}, 100, 100, "Out" }
{
	menu1.attach(new Button { Point {0, 0}, 70, 20, "M_1_1", [](Address, Address pw) {cout << "m_1_1 btn clicked" << endl; } });
	menu1.attach(new Button { Point {0, 0}, 70, 20, "M_1_2", [](Address, Address pw) {cout << "m_1_2 btn clicked" << endl; } }); 
	menu2.attach(new Button { Point {0, 0}, 70, 20, "M_2_1", [](Address, Address pw) {} });
	menu3.attach(new Button { Point {0, 0}, 70, 20, "M_3_1", [](Address, Address pw) {} });
	menu4.attach(new Button { Point {0, 0}, 70, 20, "M_4_1", [](Address, Address pw) {} });

	attach(menu1);
	attach(menu2);
	attach(menu3);
	attach(menu4);
}

//------------------------------------------------------------------------------
