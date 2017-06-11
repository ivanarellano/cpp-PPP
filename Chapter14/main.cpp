#include "Simple_window.h"
#include "Graph.h"

class Arc1 : public Shape {
	int x, y, r, s, e;
public:
	Arc1(Point c, int radius, int start, int end) :
		x(c.x), y(c.y), r(radius), s(start), e(end) {}

	void draw_lines() const {
		if (color().visibility()) 
			fl_arc(x - r, y - r, 2 * r, 2 * r, s, e);
	}
};

class Smiley : public Circle {
	Circle l_eye;
	Circle r_eye;
	Arc1 mouth;
public:
	Smiley(Point p, int r) : Circle(p, r), 
		mouth(Point{ p.x, p.y + r/6 }, r / 2, 180, 0),
		l_eye(Point{ p.x - r / 2, p.y - r / 4 }, r / 4),
		r_eye(Point{ p.x + r / 2, p.y - r / 4 }, r / 4)
	{
		set_color(Color::black);
		l_eye.set_color(Color::black);
		r_eye.set_color(Color::black);
		mouth.set_color(Color::black);
	}

	void draw_lines() const {
		Circle::draw_lines();
		l_eye.draw();
		r_eye.draw();
		mouth.draw();
	}
};

class Immobile_circle : public Circle {
	using Circle::Circle;
public:
	void move(int dx, int dy) override {}
};

struct B1 {
	virtual void vf() { cout << "B1::vf()"; };
	void f() const { cout << "B1:f()"; };
	virtual void pvf() = 0;
};

struct D1 : B1 {
	void vf() override { cout << "D1::vf()"; };
	void f() { cout << "D1::f()"; };
	void pvf() override { cout << "D1::pvf()"; };
};

struct D2 : D1 {
	void pvf() override { cout << "D2::pvf()"; };
};

struct B2{
	virtual void pvf() = 0;
};

struct D21 : B2 {
	string data;
	void pvf() override { cout << data; };
};

struct D22 : B2 {
	int n;
	void pvf() override { cout << n; };
};

// Explain the results
// #4
// If D1 does not override, B1 definition is used

// #5
// Adding a pure virtual function to B1 made it impossible to define
// It becomes an abstract class. D1 requires the pvf() function 
// defined in order for compilation to succeed.

void f(B2& b2) {
	b2.pvf();
}

int main() {
	try {
		using namespace Graph_lib;
		Point x{ 200, 100 };
		Simple_window win(x, 800, 800, "My window");

		Graph_lib::Rectangle win_r = { {0,0}, {800,800} };
		Graph_lib::Rectangle button = { { 700,0 },{ 800,100 } };
		Text label = { { button.point(0).x + button.width() / 2, button.point(0).y + button.height() / 2}, "Label" };
		Graph_lib::Image img_nebula = { {0,0},"nebula.jpg",Graph_lib::Suffix::jpg };

		
		win.attach(img_nebula);
		win.attach(button);
		win.attach(label);
		win.attach(win_r);

		//B1 b1;
		//b1.f();
		//b1.vf();

		//D1 d1;
		//d1.f();
		//d1.vf();

		//B1& b2 = d1;
		//b2.f();
		//b2.vf();

		//D2 d2;
		//d2.f();
		//d2.vf();
		//d2.pvf();

		//D21 d21;
		//d21.data = "hello world";
		//d21.pvf();

		//D22 d22;
		//d22.n = 22;
		//f(d21);
		//f(d22);

		//Smiley smile = { {200,600}, 100 };
		//win.attach(smile);

		//Immobile_circle im = { {100,100}, 10 };
		//im.set_color(Color::black);
		//im.move(2000, 200);
		//win.attach(im);

		// You can't copy a shape because = is deleted
		// Copying a shape can get problematic
		// Especially when using for pass-by-reference function argument with class hierarchies
		// Disable copy constructor and copy assignment using =delete
		// Prevents 'Slicing' classes when size of class does not match
		//Circle circle = { Point{100,100}, 10 };
		//Shape shape = circle;

		//Line t = { {300,300}, {600,300} };
		//Line b = { {300,500}, {600,500} };
		//Line l = { {300,300}, {300,500} };
		//Line r = { {600,300}, {600,500} };
		//t.set_color(Color::black);
		//b.set_color(Color::black);
		//l.set_color(Color::black);
		//r.set_color(Color::black);
		//win.attach(t);
		//win.attach(b);
		//win.attach(l);
		//win.attach(r);

		win.wait_for_button();
	}
	catch (exception& e) {

	}

	return 0;
}
