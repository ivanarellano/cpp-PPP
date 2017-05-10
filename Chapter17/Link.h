#pragma once
#include <string>

struct Link {
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value { v }, prev { p }, succ { s }
	{
	}

	std::string value;
	Link* prev;
	Link* succ;

	// insert n before p; return n
	Link* insert(Link* p, Link* n);

	// much like insert (see exercise 11)
	Link* add(Link* p, Link* n);

	// remove *p from list; return p's successor
	Link* erase(Link* p);

	// find s in list; return nullptr for "not found"
	Link* find(Link* p, const std::string& s);

	// move n positions in list; return nullptr for "not found"
	// positive n moves forward, negative backward
	Link* advance(Link* p, int n);
};