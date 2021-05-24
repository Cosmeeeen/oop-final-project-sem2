#include "House.h"
#include "Property.h"
#include <string>

House::House() : Property(){
    this->floors = 0;
}

House::House(const House& other) : Property((Property &) other){
    this->floors = other.floors;
}

House::House(int id, int surface, int rooms, int price, std::string street, int floors) : Property(id, surface, rooms, price, street) {
    this->floors = floors;
}

House::~House() = default;

int House::getFloors() const{
    return this->floors;
}

void House::setFloors(int newFloors){
    this->floors = newFloors;
}

House* House::clone(){
    return new House(
        this->id,
        this->surface,
        this->rooms,
        this->price,
        this->street,
        this->floors
    );
}

House& House::operator=(const House& other){
    if(&other != this){
        Property::operator=(other);
        this->setFloors(other.floors);
    }
    return *this;
}

bool House::operator==(const House& other){
    return Property::operator==(other) && this->floors == other.floors;
}

std::string House::toString(bool forFile){
    std::string result;
    if(forFile){
        result =
                Property::toString(true) + " " +
                std::to_string(this->floors);
    } else {
        result =
                Property::toString() + " " +
                std::to_string(this->floors) + "floors";
    }
    return result;
}
