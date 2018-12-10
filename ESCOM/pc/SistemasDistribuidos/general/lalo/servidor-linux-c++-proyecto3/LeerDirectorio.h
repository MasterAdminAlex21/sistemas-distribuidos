#ifndef LEERDIRECTORIO_H
#define LEERDIRECTORIO_H

#include <vector>
#include <string>
using namespace std;

class LeerDirectorio {
private:
	string directorio;
public:
	LeerDirectorio(const string&);
	vector<string> evaluar();
};

#endif
