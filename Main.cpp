#include <iostream>
#include "Tests.h"
#include "UserInterface.h"
#include "FileRepoSTLTemplate.h"

using namespace std;

int main()
{
	TestDomain();
	TestRepo();
	TestService();
	
	//RepoSTLTemplate<Cake> mainRepo;
	FileRepoSTLTemplate<Cake> mainRepo("cakes.txt");
	Service mainService(&mainRepo);
	UserInterface mainUI(mainService);
	mainUI.startLoop();
	
	return 0;
}