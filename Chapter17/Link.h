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
};

// insert n before p; return n
Link* insert(Link* p, Link* n)
{
	if (n == nullptr) return p;
	if (p == nullptr) return n;

	if (p->prev) p->prev->succ = n;

	n->prev = p->prev;
	n->succ = p;
	p->prev = n;

	return n;
}

// much like insert (see exercise 11)
Link* add(Link* p, Link* n)
{
	return nullptr;
}

// remove *p from list; return p's successor
Link* erase(Link* p)
{
	if (p == nullptr) return nullptr;

	if (p->prev) p->prev->succ = p->succ;
	if (p->succ) p->succ->prev = p->prev;

	return p->succ;
}

// find s in list; return nullptr for "not found"
Link* find(Link* p, const std::string& s)
{
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}

	return nullptr;
}

// move n positions in list; return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n)
{
	if (p == nullptr) return nullptr;

	if (0 < n) {
		// move forward
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else {
		// move backward
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}

	return p;
}