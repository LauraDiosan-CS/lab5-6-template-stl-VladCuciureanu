#include "Tests.h"
#include <assert.h>
#include <iostream>
#include "FileRepoSTLTemplate.h"

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
	Cake c3(3, "Velvet", "red stuff", 13);
	Cake c4(4, "Cupcake", "cup-sized stuff", 14);
	RepoSTLTemplate<Cake> repo;
	repo.addElem(c1);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	assert(repo.dim() == 3);
	assert(repo.getAll()[0] == c1);
	assert(repo.getAll()[1] == c2);
	assert(repo.getAll()[2] == c3);
	assert(repo.findElemById(1) != repo.getEnd());
	assert(repo.findElemById(4) == repo.getEnd());
	repo.delElem(3);
	assert(repo.dim() == 2);
	assert(repo.findElemById(3) == repo.getEnd());
	assert(strcmp(c2.getName(), "Eclair") == 0);
	repo.updateElem(2, Cake(2, "Lavacake", "stuff", 30));
	assert(strcmp(repo.getAll()[1].getName(), "Eclair") != 0);
}

void TestService()
{
	FileRepoSTLTemplate<Cake> repo("test.txt");
	Service service(&repo);
	service.addCake("p4", "vanilie", 11);
	assert(service.getCakes().size() == 4);
	service.deleteCake(3);
	assert(service.getCakes().size() == 3);
	service.updateCake(0, "", "zahar,faina,vanilie", 15);
	std::map<std::string, double> results = service.avgIngredients();
	assert(results["zahar"] == 17.5);
	assert(results["unt"] == 10);
	assert(results["vanilie"] == 15);
	assert(results["faina"] == 12.5);
	assert(results["ciocolata"] == 15);
}