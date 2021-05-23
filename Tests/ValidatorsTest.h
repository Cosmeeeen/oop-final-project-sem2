#pragma once

class ValidatorTest{
private:
    void testPropertyValidator();
    void testHouseValidator();
    void testApartmentValidator();
public:
    ValidatorTest();
    ~ValidatorTest();
    void runAll();
};