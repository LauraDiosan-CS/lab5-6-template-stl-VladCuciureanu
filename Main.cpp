#include <iostream>
#include "Tests.h"

using namespace std;

int main()
{
	TestDomain();
	TestRepo();
	TestService();
	RepoSTLTemplate<Cake> mainRepo;
	Service mainService(mainRepo, "cakes.txt");
	return 0;
}