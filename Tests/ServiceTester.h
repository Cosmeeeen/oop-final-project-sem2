#pragma once
class ServiceTester{
private:
    void testGetAll();
    void testAddHouse();
    void testAddApartment();
    void testUpdateHouse();
    void testUpdateApartment();
    void testDeleteProperty();
public:
    ServiceTester();
    ~ServiceTester();

    void runAll();
};