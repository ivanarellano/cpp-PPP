#include "../../../code_snippets/std_lib_facilities.h"
#include <string>

struct Monster {
	string name;
};

void fillVector(vector<Monster>& output, string& fileName) {
	ifstream ist { fileName };
	if (!ist) {
		error("can't open input file", fileName);
	}

	string name;
	while (ist >> name) {
		output.push_back(Monster{ name });

	}
}

void writeFile(const Monster monsters[], string& fileName) {
	ofstream ost { fileName };
	if (!ost) {
		error("error opening file", fileName);
	}

	for (int i = 0; i < sizeof(monsters); ++i) {
		ost << monsters[i].name;
	}
}

int main() {
	Monster m[] {
		Monster {"ivan"},
		Monster {"mike"},
		Monster {"tony"},
		Monster {"jordan"}
	};

	vector<Monster> monsters;
	for each (Monster monster in m) {
		monsters.push_back(monster);
	}

	cout << "Please enter name of output file:";
	
	string oname;
	cin >> oname;

	ofstream ost { oname };
	if (!ost) {
		error("can't open output file", oname);
	}

	for (auto& monster : monsters) {
		ost << monster.name;
	}

	ost.close();

	//cout << "Please enter input file name:";
	//string iname;
	//cin >> iname;

	//vector<Monster> mons;
	//fillVector(mons, iname);

	//for (auto& s : mons) {
	//	cout << s.name << endl;
	//}

	keep_window_open();
	return 0;
}