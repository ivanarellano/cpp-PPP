#include "Utils.h"
#include "Drill.h"
#include "Exercise.h"

void ch_17_9_5()
{
	std::cout << "ch_17_9_5()" << std::endl;

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
	std::cout << "ch_17_10()" << std::endl;

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

void drills()
{
	drill_1_3();
	std::cout << std::endl;

	drill_4();
	std::cout << std::endl;

	drill_5();
	std::cout << std::endl;

	drill_6();
	std::cout << std::endl;

	drill_7();
	std::cout << std::endl;

	drill_8();
	std::cout << std::endl;

	drill_10();
	std::cout << std::endl;

	drill_p2_1_13();
	std::cout << std::endl;
}

void chapter()
{
	ch_17_9_5();
	std::cout << std::endl;

	ch_17_10();
	std::cout << std::endl;
}

int main()
{
	ex_1();
	ex_2();

	char hello_world[] = "Hello, World!";
	to_lower(hello_world);

	const char* a = findx("Test a thing, another thing", "thing");
	std::cout << a << std::endl;

	keep_window_open();
	return 0;
}