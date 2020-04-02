#pragma once
#include <vector>

template <class T>
class RepoSTLTemplate
{
private:
	std::vector <T> elem;

public:
	RepoSTLTemplate();
	void addElem(T);
	bool findElem(T);
	void delElem(T);
	//void updateElem(Cake&, int, const char*, const char*, double);
	T getItemFromPos(int);
	std::vector<T>getAll();
	int dim();
	~RepoSTLTemplate();
};

