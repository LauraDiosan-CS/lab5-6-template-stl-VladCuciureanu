#pragma once
#include "Cake.h"
#include <vector>

class RepoSTL
{
private:
	std::vector <Cake> elem;

public:
	RepoSTL();
	void addElem(Cake);
	bool findElem(Cake);
	void delElem(Cake);
	void updateElem(Cake&, int, const char*, const char*, double);
	Cake getItemFromPos(int);
	std::vector<Cake>getAll();
	int dim();
	~RepoSTL();
};

