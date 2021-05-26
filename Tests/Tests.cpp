#include "Tests.h"
#include "EntitiesTester.h"
#include "ValidatorsTest.h"
#include "RepoTester.h"
#include "RepoFileTester.h"
#include <cassert>
#include <iostream>

void runAllTests(){
    EntitiesTester propertyTester;
    propertyTester.runAll();

    ValidatorTest validatorTest;
    validatorTest.runAll();

    RepoTester repoTester;
    repoTester.runAll();

    RepoFileTester repoFileTester;
    repoFileTester.runAll();

    std::cout << "All test passed. Welcome!\n";
}
