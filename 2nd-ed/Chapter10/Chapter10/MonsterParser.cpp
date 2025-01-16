#include <fstream>
#include <stdexcept>

#include "MonsterParser.h"

//std::vector<Monster> MonsterParser::parse(const std::string& fileName) {
//	std::vector<Monster> monsters;
//	
//	std::ifstream ist { fileName };
//	ist.exceptions(ist.exceptions() | std::ios_base::badbit);
//	if (!ist) {
//		std::runtime_error("error opening file");
//	}
//	
//	std::string name;
//	while (ist >> name) {
//		monsters.push_back(Monster{ name });
//	}
//	
//	/*MonsterParser::endOfLoop(ist, '|', "bad termination of file");*/
//	
//	return monsters;
//}
