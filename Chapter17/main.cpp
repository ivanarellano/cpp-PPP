#include "Link.h"
#include <iostream>

void print_all(Link* p)
{
	std::cout << "{";

	while (p) {
		std::cout << p->value;
		if (p = p->succ) std::cout << ", ";
	}

	std::cout << "}";
}

void ch_17_9_5()
{
	Link* norse_gods = new Link{ "Thor" };
	norse_gods = norse_gods->insert(norse_gods, new Link{ "Odin" });
	norse_gods = norse_gods->insert(norse_gods, new Link{ "Zeus" });
	norse_gods = norse_gods->insert(norse_gods, new Link{ "Freia" });
	// N: "Freia" -> "Zeus" -> "Odin" -> "Thor"

	Link* greek_gods = new Link{ "Hera" };
	greek_gods = greek_gods->insert(greek_gods, new Link{ "Athena" });
	greek_gods = greek_gods->insert(greek_gods, new Link{ "Mars" });
	greek_gods = greek_gods->insert(greek_gods, new Link{ "Poseidon" });
	// G: "Poseidon" -> "Mars" -> "Athena" -> "Hera"

	Link* p = greek_gods->find(greek_gods, "Mars");
	if (p) p->value = "Ares";
	// G: "Poseidon" -> "Ares" -> "Athena" -> "Hera"

	Link* p2 = norse_gods->find(norse_gods, "Zeus");
	if (p2) {
		// if we're erasing pointer to norse_gods,
		// set norse_gods pointer to next link
		if (p2 == norse_gods) norse_gods = p2->succ;

		norse_gods->erase(p2);
		greek_gods = greek_gods->insert(greek_gods, p2);
	}
	// N: "Freia" -> "Odin" -> "Thor
	// G: "Zeus" -> "Poseidon" -> "Ares" -> "Athena" -> "Hera"

	print_all(norse_gods);
	std::cout << std::endl;

	print_all(greek_gods);
	std::cout << std::endl;
}

int main()
{
	ch_17_9_5();

	char ch;
	std::cout << "Enter a key and enter to exit.";
	std::cin >> ch;

	return 0;
}