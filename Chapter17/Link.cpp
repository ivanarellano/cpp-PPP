#include "Link.h"

Link* Link::insert(Link* p, Link* n)
{
	if (n == nullptr) return p;
	if (p == nullptr) return n;

	if (p->prev) p->prev->succ = n;

	n->prev = p->prev;
	n->succ = p;
	p->prev = n;

	return n;
}

Link* Link::add(Link* p, Link* n)
{
	return nullptr;
}

Link* Link::erase(Link* p)
{
	if (p == nullptr) return nullptr;

	if (p->prev) p->prev->succ = p->succ;
	if (p->succ) p->succ->prev = p->prev;

	return p->succ;
}

Link* Link::find(Link* p, const std::string& s)
{
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}

	return nullptr;
}

Link* Link::advance(Link* p, int n)
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
