#pragma once
#include "Property.h"
#include <string>

class House : public Property{
private:
    int floors;
public:
    House();
    House(const House& other);
    House(int id, int surface, int rooms, int price, std::string street, int floors);
    ~House();

    int getFloors () const;
    void setFloors(int newFloors);

    House* clone();

    House& operator=(const House& other);
    bool operator==(const House& other);

    std::string toString(bool forFile = false);
};