#include "Tests.h"
#include "EntitiesTester.h"
#include "ValidatorsTest.h"
#include "RepoTester.h"
#include <cassert>
#include <iostream>

void runAllTests(){
    EntitiesTester propertyTester;
    propertyTester.runAllTests();

    ValidatorTest validatorTest;
    validatorTest.runAll();

    RepoTester repoTester;
    repoTester.runAll();

    std::cout << "All test passed. Welcome!\n";
}
