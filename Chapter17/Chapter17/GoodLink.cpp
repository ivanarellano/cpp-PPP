#include "GoodLink.h"

GoodLink* GoodLink::insert(GoodLink* n)
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	
	n->succ = this;

	if (prev) prev->succ = n;

	n->prev = prev;
	prev = n;

	return n;
}

GoodLink* GoodLink::add(GoodLink* n)
{
	return nullptr;
}

GoodLink* GoodLink::erase()
{
	if (this == nullptr) return nullptr;

	if (prev) prev->succ = succ;
	if (succ) succ->prev = prev;

	return succ;
}

GoodLink* GoodLink::find(const std::string& s)
{
	GoodLink* p = this;
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}

	return nullptr;
}

const GoodLink * GoodLink::find(const std::string & s) const
{
	return nullptr;
}

GoodLink* GoodLink::advance(int n) const
{
	return nullptr;
}
