#include "work_selection.h"

int main()
{
	Work work{ Work::Drill };

	switch (work)
	{
	case Work::Chapter: return Chapter::main();
	case Work::Drill: return Drill::main();
	case Work::Ex1: return Ex1::main();
	case Work::Ex2: return Ex2::main();
	case Work::Ex3: return Ex3::main();
	case Work::Ex4: return Ex4::main();
	case Work::Ex5: return Ex5::main();
	case Work::Ex6: return Ex6::main();
	case Work::Ex7: return Ex7::main();
	case Work::Ex8: return Ex8::main();
	case Work::Ex9: return Ex9::main();
	case Work::Ex10: return Ex10::main();
	case Work::Ex11: return Ex11::main();
	case Work::Ex12: return Ex12::main();
	case Work::Ex13: return Ex13::main();
	case Work::Ex14: return Ex14::main();
	case Work::Ex15: return Ex15::main();
	case Work::Ex16: return Ex16::main();
	default:
		break;
	}

	return 0;
}