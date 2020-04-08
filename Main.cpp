#include <iostream>
#include "Tests.h"
#include "UserInterface.h"

using namespace std;

int main()
{
	TestDomain();
	TestRepo();
	TestService();
	RepoSTLTemplate<Cake> mainRepo;
	Service mainService(mainRepo, "cakes.txt");
	UserInterface mainUI(mainService);
	mainUI.startLoop();
	return 0;
}