#include <fstream>
#include <stdexcept>

#include "MonsterWriter.h"

//void MonsterWriter::write(const std::vector<Monster>& monsters, const std::string & fileName) {
//	std::ofstream ost { fileName };
//	if (!ost) {
//		std::runtime_error("error opening file to write");
//	}
//
//	for (auto& monster : monsters) {
//		ost << monster.name;
//	}
//}

//std::istream& operator<<(std::istream& is, Monster& mon) {
//	std::string name;
//	is >> name;
//
//	if (!is) { 
//		return is;
//	
//	}
//	mon = Monster { name };
//	
//	return is;
//}