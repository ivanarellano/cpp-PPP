#include "Simple_window.h"
#include "Graph.h"

int main() {
	try {
		using namespace Graph_lib;

		Point x{ 100, 100 };
		Simple_window win(x, 600, 400, "My window");


		//Line horizontal{ x, Point{200, 100} };
		//horizontal.set_color(Color::black);

		//Line vertical{ Point{150,50}, Point {150, 150} };
		//vertical.set_color(Color::black);

		//win.attach(horizontal);
		//win.attach(vertical);


		//Lines lines;
		//lines.add(Point{ 100, 100 }, Point{ 200, 100 });
		//lines.add(Point{ 150,50 }, Point{ 150,150 });
		//lines.set_color(Color::black);
		//win.attach(lines);

		//Lines lines2 = {
		//	{ { 100, 100 }, { 200, 100 } },
		//	{ { 150,50 }, { 150,150 } }
		//};
		//lines2.set_color(Color::black);
		//win.attach(lines2);


		//int x_size = win.x_max();
		//int y_size = win.y_max();
		//int x_grid = 80;
		//int y_grid = 40;

		//Lines grid;
		//for (int x = x_grid; x < x_size; x += x_grid) {
		//	grid.add(Point{ x, 0 }, Point{ x, y_size });
		//}

		//for (int y = y_grid; y < y_size; y += y_grid) {
		//	grid.add(Point{ 0, y }, Point{ x_size, y });
		//}

		//grid.set_color(Color::black);
		//grid.set_style(Line_style{ Line_style::dash, 2 });
		//win.attach(grid);


		//Open_polyline opl = {
		//	{100, 100}, {150, 200}, {250, 250}, {300,200}
		//};
		//opl.set_color(Color::red);
		//win.attach(opl);


		//Closed_polyline cpl = {
		//	{ 200, 200 },{ 250, 300 },{ 350, 350 },{ 400,300 }
		//};
		//cpl.set_color(Color::blue);
		//win.attach(cpl);


		//Graph_lib::Polygon poly = {
		//	{100, 0}, {150,100}, {250,150}, {300,100}
		//};
		//poly.set_color(Color::dark_yellow);
		//win.attach(poly);


		//Vector_ref<Graph_lib::Rectangle> palette;
		// 
		//for (int i = 0; i < 16; ++i) {
		//	for (int j = 0; j < 16; ++j) {
		//		palette.push_back(new Graph_lib::Rectangle{ Point{ i * 20, j * 20 }, 20,20 });
		//		palette[palette.size() - 1].set_fill_color(Color{ i * 16 + j});
		//		win.attach(palette[palette.size() - 1]);
		//	}
		//}

		Circle c1{ Point{100,200}, 50 };
		Circle c2{ Point{150,200},100 };
		Circle c3{ Point{200,200},150 };
		win.attach(c1);
		win.attach(c2);
		win.attach(c3);

		win.wait_for_button();
	}
	catch (exception& e) {

	}

	return 0;
}
