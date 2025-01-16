#pragma once

/*
This class defines interfaces to implementations for Chapter 19.

Why programmatically select the work? Well, for learning reasons.

The natural way is to maintain multiple programs is to put multiple
projects in a single solution. To run a project, Right-click 
`Solution Explorer`, select `Set as Startup Project`, then click 
`Start` button to run it.
*/

enum class Work {
	Chapter, Drill, Ex1, Ex2, Ex3, Ex4, Ex5, Ex6, Ex7, Ex8, Ex9, Ex10, Ex11, Ex12, Ex13, Ex14, Ex15, Ex16
};

namespace Chapter {
	int main();
}

namespace Drill {
	int main();
}

namespace Ex1 {
	int main();
}

namespace Ex2 {
	int main();
}

namespace Ex3 {
	int main();
}

namespace Ex4 {
	int main();
}

namespace Ex5 {
	int main();
}

namespace Ex6 {
	int main();
}

namespace Ex7 {
	int main();
}

namespace Ex8 {
	int main();
}

namespace Ex9 {
	int main();
}

namespace Ex10 {
	int main();
}
namespace Ex11 {
	int main();
}

namespace Ex12 {
	int main();
}

namespace Ex13 {
	int main();
}

namespace Ex14 {
	int main();
}

namespace Ex15 {
	int main();
}

namespace Ex16 {
	int main();
}
