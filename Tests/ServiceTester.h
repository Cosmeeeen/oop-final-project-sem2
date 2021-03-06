#pragma once
class ServiceTester{
private:
    void testGetAll();
    void testAddHouse();
    void testAddApartment();
    void testUpdateHouse();
    void testUpdateApartment();
    void testDeleteProperty();
    void testGetMostExpensive();
    void testGetSorted();
    void testGetByRooms();
public:
    ServiceTester();
    ~ServiceTester();

    void runAll();
};