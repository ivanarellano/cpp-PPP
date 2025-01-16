#include "../../../Code Snippets/std_lib_facilities.h"
#include <iostream>
#include <fstream>

// 1.
struct Point {
	int x, y;
	Point() : x{ 0 }, y{ 0 } {}
	Point(int x, int y) : x{ x }, y{ y } {}
};

// 3.
std::ostream& operator<<(std::ostream& os, const Point& point) {
	return os << '(' << point.x << ',' << point.y << ')';
}

//2. 
// format: (x,y)
std::istream& operator>>(std::istream& is, Point& point) {
	int x, y;
	char lparan, comma, rparan;
	is >> lparan >> x >> comma >> y >> rparan;
	if (!is) {
		is.unget();
		is.clear(std::ios_base::failbit);
	}
	point = Point{ x, y };
	return is;
}

//7.
bool operator==(const Point& p1, const Point& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

//int main() {
//	// 2.
//	vector<Point> ogPoints;
//	std::cout << "please input seven pairs of points (x,y)" << std::endl;
//	for (int i = 0; i<1; ++i) {
//		Point p;
//		std::cin >> p;
//		ogPoints.push_back(p);
//	}
//
//	// 3.
//	std::cout << "printing ogPoints" << std::endl;
//	for (Point p : ogPoints) {
//		std::cout << p << endl;
//	}
//
//	const std::string file = "mydata.txt";
//
//	// 4.
//	std::ofstream ofs{ file };
//	if (!ofs) {
//		std::runtime_error("can't open file");
//	}
//	
//	for (Point p : ogPoints) {
//		ofs << p << endl;
//	}
//
//	// 5.
//	vector<Point> processedPoints;
//	std::ifstream ifs { file };
//	while (true) {
//		Point p;
//		if (!(ifs >> p)) break;
//		processedPoints.push_back(p);
//	}
//	ifs.close();
//
//	// 6.
//	std::cout << "printing processedPoints" << std::endl;
//	for (Point p : processedPoints) {
//		std::cout << p << endl;
//	}
//
//	// 7.
//	if (ogPoints.size() != processedPoints.size()) {
//		std::cout << "something's wrong!" << std::endl;
//	}
//
//	for (Point ogP : ogPoints) {
//		for (Point pP : processedPoints) {
//			if (!(ogP == pP)) {
//				std::cout << "something's wrong!" << std::endl;
//			}
//		}
//	}
//
//	keep_window_open();
//	return 0;
//}