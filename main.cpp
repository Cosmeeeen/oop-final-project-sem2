#include <iostream>
#include "Tests/Tests.h"
#include "UI/UI.h"
#include "Service/Service.h"
#include "Repository/RepoFile.h"
using namespace std;

int main(){
    runAllTests();


    RepoFile* repo = new RepoFile("productionRepo.txt");
    Service service(repo);
    UI ui(service);

    ui.runUI();

    return 0;
}