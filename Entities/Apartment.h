#pragma once
#include "Property.h"
#include <string>

class Apartment : public Property{
private:
    int floor;
public:
    Apartment();
    Apartment(const Apartment &other);
    Apartment(int id, int surface, int rooms, int price, std::string street, int floor);
    ~Apartment();

    int getFloor() const;
    void setFloor(int newFloor);

    Apartment* clone();

    Apartment& operator=(const Apartment& other);
    bool operator==(const Apartment& other);

    std::string toString(bool forFile = false);
};