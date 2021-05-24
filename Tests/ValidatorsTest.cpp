#include "ValidatorsTest.h"
#include "../Validation/ValidationException.h"
#include "../Validation/PropertyValidator.h"
#include "../Validation/HouseValidator.h"
#include "../Validation/ApartmentValidator.h"
#include "../Entities/Property.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include <cassert>

void ValidatorTest::testPropertyValidator() {
    PropertyValidator val;

    Property* p1 = new Property(
            1,
            100,
            3,
            1000,
            "testing"
            );
    try{
        val.validate(p1);
    }catch(...){
        assert(false);
    }

    Property* p2 = new Property(
            2,
            -100,
            3,
            1000,
            "testing"
            );
    try{
        val.validate(p2);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    Property* p3 = new Property(
            2,
            100,
            -3,
            1000,
            "testing"
    );
    try{
        val.validate(p3);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    Property* p4 = new Property(
            2,
            100,
            3,
            -1000,
            "testing"
    );
    try{
        val.validate(p4);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    Property* p5 = new Property(
        2,
        100,
        3,
        1000,
        "testing 123"
    );
    try{
        val.validate(p5);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

void ValidatorTest::testHouseValidator() {
    HouseValidator val;
    House* h1 = new House(
            1,
            100,
            3,
            1000,
            "testing",
            2
            );
    try{
        val.validate(h1);
    }catch(...){
        assert(false);
    }

    House* h2 = new House(
            1,
            100,
            3,
            1000,
            "testing",
            -2
            );
    try{
        val.validate(h2);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    delete h1;
    delete h2;
}

void ValidatorTest::testApartmentValidator() {
    ApartmentValidator val;
    Apartment* a1 = new Apartment(
            1,
            100,
            3,
            1000,
            "testing",
            2
            );
    try{
        val.validate(a1);
    }catch(...){
        assert(false);
    }

    Apartment* a2 = new Apartment(
            1,
            100,
            3,
            1000,
            "testing",
            -2
            );
    try{
        val.validate(a2);
    }catch(ValidationException& e){
        assert(true);
    }catch(...){
        assert(false);
    }

    delete a1;
    delete a2;
}

ValidatorTest::ValidatorTest() = default;

ValidatorTest::~ValidatorTest() = default;

void ValidatorTest::runAll(){
    testPropertyValidator();
    testHouseValidator();
    testApartmentValidator();
}