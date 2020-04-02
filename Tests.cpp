#include "Tests.h"
#include <assert.h>

void TestDomain()
{
	Cake c1(1, "Strudel", "oua, mere, habar n-am", 11);
	assert(strcmp(c1.getName(), "Strudel") == 0);
	assert(strcmp(c1.getIngredients(), "oua, mere, habar n-am") == 0);
	assert(c1.getId() == 1);
	assert(c1.getPrice() == 11);
	Cake c2(2, "Eclair", "ceva bun", 12);
	assert(!(c1 == c2));
	c2 = c1;
	assert(c2 == c1);
	Cake c3;
	assert(c3.getId() == 0);
	assert(c3.getIngredients() == NULL);
	assert(c3.getName() == NULL);
	assert(c3.getPrice() == 0);
}

void TestRepo()
{
	Cake c1(1, "Strudel", "oua, mere, habar n-am", 11);
	Cake c2(2, "Eclair", "ceva bun", 12);
	Cake c3(2, "Velvet", "red stuff", 13);
	Cake c4(2, "Cupcake", "cup-sized stuff", 14);
	RepoSTL repo;
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	assert(repo.dim() == 3);
	assert(repo.getAll()[0] == c1);
	assert(repo.getAll()[1] == c2);
	assert(repo.getAll()[2] == c3);
	assert(repo.findElem(c1) == true);
	assert(repo.findElem(c4) == false);
	repo.delElem(c3);
	assert(repo.dim() == 2);
	assert(repo.findElem(c3) == false);
	assert(strcmp(c2.getName(), "Eclair") == 0);
	repo.updateElem(c2, 2, "Lavacake", "blabla", 30);
	assert(strcmp(c2.getName(), "Eclair") != 0);
}