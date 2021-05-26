#include "EntitiesTester.h"
#include <string>
#include <cassert>
#include <iostream>

void EntitiesTester::constructorsTests() {

    // Default constructor
    Property p1;
    assert(p1.getId() == 0);
    assert(p1.getPrice() == 0);
    assert(p1.getSurface() == 0);
    assert(p1.getRooms() == 0);
    assert(p1.getStreet().empty());

    House h1;
    assert(h1.getId() == 0);
    assert(h1.getSurface() == 0);
    assert(h1.getPrice() == 0);
    assert(h1.getStreet().empty());
    assert(h1.getFloors() == 0);

    Apartment a1;
    assert(a1.getId() == 0);
    assert(a1.getSurface() == 0);
    assert(a1.getPrice() == 0);
    assert(a1.getStreet().empty());
    assert(a1.getFloor() == 0);

    // Reference constructor
    Property p2 = this->testProperty;
    assert(p2.getId() == 1);
    assert(p2.getSurface() == 100);
    assert(p2.getRooms() == 3);
    assert(p2.getPrice() == 2000);
    assert(p2.getStreet() == "testAddress");

    House h2 = this->testHouse;
    assert(h2.getFloors() == 1);

    Apartment a2 = this->testApartment;
    assert(a2.getFloor() == 4);

    // Parameters constructor
    Property p3(
        2,
        200,
        4,
        4000,
        "testing"
    );
    assert(p3.getId() == 2);
    assert(p3.getSurface() == 200);
    assert(p3.getRooms() == 4);
    assert(p3.getPrice() == 4000);
    assert(p3.getStreet() == "testing");

    House h3(
        2,
        200,
        4,
        4000,
        "testing",
        2
    );
    assert(h3.getFloors() == 2);

    Apartment a3(
        2,
        200,
        4,
        4000,
        "testing",
        2
    );
}

void EntitiesTester::settersTest() {
    Property p1 = this->testProperty;
    p1.setId(2);
    p1.setPrice(50);
    p1.setSurface(500);
    p1.setRooms(2);
    p1.setStreet("test123");

    assert(p1.getId() == 2);
    assert(p1.getPrice() == 50);
    assert(p1.getSurface() == 500);
    assert(p1.getRooms() == 2);
    assert(p1.getStreet() == "test123");

    House h1 = this->testHouse;
    h1.setFloors(10);
    assert(h1.getFloors() == 10);

    Apartment a1 = this->testApartment;
    a1.setFloor(12);
    assert(a1.getFloor() == 12);
}

void EntitiesTester::operatorsTests() {
    Property p1;
    p1 = this->testProperty;
    assert(p1 == this->testProperty);
    assert(p1.getId() == 1);
    assert(p1.getSurface() == 100);
    assert(p1.getRooms() == 3);
    assert(p1.getPrice() == 2000);
    assert(p1.getStreet() == "testAddress");

    House h1;
    h1 = this->testHouse;
    assert(h1 == this->testHouse);
    assert(h1.getFloors() == 1);

    Apartment a1;
    a1 = this->testApartment;
    assert(a1 == this->testApartment);
    assert(a1.getFloor() == 4);
}

void EntitiesTester::toStringTests() {
    std::string result = this->testProperty.toString();

    assert(result == "1. 100m3 3rooms 2000eur testAddress");

    result = this->testHouse.toString();
    assert(result == "2. 100m3 3rooms 2000eur testAddress 1floors");

    result = this->testApartment.toString();
    assert(result == "3. 100m3 3rooms 2000eur testAddress 4floor");
}

EntitiesTester::EntitiesTester(){
    this->testProperty = Property(
        1,
        100,
        3,
        2000,
        "testAddress"
    );

    this->testHouse = House(
        2,
        100,
        3,
        2000,
        "testAddress",
        1
    );

    this->testApartment = Apartment(
        3,
        100,
        3,
        2000,
        "testAddress",
        4
    );
}

EntitiesTester::~EntitiesTester() = default;

void EntitiesTester::runAll(){
    this->constructorsTests();
    this->settersTest();
    this->operatorsTests();
    this->toStringTests();
}