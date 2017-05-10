#include "Link.h"
#include "GoodLink.h"
#include "vector.h"
#include <iostream>

void keep_window_open()
{
	char ch;
	std::cout << "Enter a key and enter to exit.";
	std::cin >> ch;
}

void print_all(Link* p)
{
	std::cout << "{";

	while (p) {
		std::cout << p->value;
		if (p = p->succ) std::cout << ", ";
	}

	std::cout << "}";
}

void print_all(GoodLink* p)
{
	std::cout << "{";

	while (p) {
		std::cout << p->value;
		if (p = p->next()) std::cout << ", ";
	}

	std::cout << "}";
}

void ch_17_9_5()
{
	Link* norse_gods = new Link{ "Thor" };
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Zeus" });
	norse_gods = insert(norse_gods, new Link{ "Freia" });
	// N: "Freia" -> "Zeus" -> "Odin" -> "Thor"

	Link* greek_gods = new Link{ "Hera" };
	greek_gods = insert(greek_gods, new Link{ "Athena" });
	greek_gods = insert(greek_gods, new Link{ "Mars" });
	greek_gods = insert(greek_gods, new Link{ "Poseidon" });
	// G: "Poseidon" -> "Mars" -> "Athena" -> "Hera"

	Link* p = find(greek_gods, "Mars");
	if (p) p->value = "Ares";
	// G: "Poseidon" -> "Ares" -> "Athena" -> "Hera"

	Link* p2 = find(norse_gods, "Zeus");
	if (p2) {
		// if we're erasing pointer to norse_gods,
		// set norse_gods pointer to next link
		if (p2 == norse_gods) norse_gods = p2->succ;

		erase(p2);
		greek_gods = insert(greek_gods, p2);
	}
	// N: "Freia" -> "Odin" -> "Thor
	// G: "Zeus" -> "Poseidon" -> "Ares" -> "Athena" -> "Hera"

	print_all(norse_gods);
	std::cout << std::endl;

	print_all(greek_gods);
	std::cout << std::endl;
}

void ch_17_10()
{
	GoodLink* norse_gods = new GoodLink{ "Thor" };
	norse_gods = norse_gods->insert(new GoodLink{ "Odin" });
	norse_gods = norse_gods->insert(new GoodLink{ "Zeus" });
	norse_gods = norse_gods->insert(new GoodLink{ "Freia" });

	GoodLink* greek_gods = new GoodLink{ "Hera" };
	greek_gods = greek_gods->insert(new GoodLink{ "Athena" });
	greek_gods = greek_gods->insert(new GoodLink{ "Mars" });
	greek_gods = greek_gods->insert(new GoodLink{ "Poseidon" });

	GoodLink* p = greek_gods->find("Mars");
	if (p) p->value = "Ares";

	GoodLink* p2 = norse_gods->find("Zeus");
	if (p2) {
		if (p2 == norse_gods) norse_gods = p2->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}

	print_all(norse_gods);
	std::cout << std::endl;

	print_all(greek_gods);
	std::cout << std::endl;
}

void ch_18_2()
{
	vector v1 = { 1, 2, 3 };
	vector v2(3);

	vector v3(3);
	v3.set(2, 2.2);
	vector v4 = v3;
}

int main()
{
	ch_17_9_5();
	std::cout << std::endl;

	ch_17_10();
	std::cout << std::endl;

	ch_18_2();

	keep_window_open();

	return 0;
}