#include "Tests.h"
#include "EntitiesTester.h"
#include "ValidatorsTest.h"
#include <cassert>
#include <iostream>

void runAllTests(){
    EntitiesTester propertyTester;
    propertyTester.runAllTests();

    ValidatorTest validatorTest;
    validatorTest.runAll();

    std::cout << "All test passed. Welcome!\n";
}
