#pragma once
#include <string>

struct Link {
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value{ v }
	{}

	std::string value;

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const;

	Link* advance(int n) const;

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};