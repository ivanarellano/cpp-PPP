#pragma once
#include <string>

class GoodLink {
public:
	GoodLink(const std::string& v, GoodLink* p = nullptr, GoodLink* s = nullptr)
		: value{ v }, prev{ p }, succ{ s }
	{}

	std::string value;

	// insert n before this object
	GoodLink* insert(GoodLink* n);

	// insert n after this object
	GoodLink* add(GoodLink* n);

	// remove this object from list
	GoodLink* erase();

	// find s in list
	GoodLink* find(const std::string& s);

	// find s in const list (see ch 18.5.1)
	const GoodLink* find(const std::string& s) const;

	// move n positions in list
	GoodLink* advance(int n) const;

	GoodLink* next() const { return succ; }
	GoodLink* previous() const { return prev; }
private:
	GoodLink* prev;
	GoodLink* succ;
};