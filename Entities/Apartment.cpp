#include "Apartment.h"
#include "Property.h"
#include <string>

Apartment::Apartment() : Property() {
    this->floor = 0;
}

Apartment::Apartment(const Apartment &other) : Property((Property &) other){
    this->floor = other.floor;
}

Apartment::Apartment(int id, int surface, int rooms, int price, std::string street, int floor) : Property(id, surface, rooms, price, street) {
    this->floor = floor;
}

Apartment::~Apartment() = default;

int Apartment::getFloor() const{
    return this->floor;
}

void Apartment::setFloor(int newFloor){
    this->floor = newFloor;
}

Apartment* Apartment::clone(){
    return new Apartment(
        this->id,
        this->surface,
        this->rooms,
        this->price,
        this->street,
        this->floor
    );
}

Apartment& Apartment::operator=(const Apartment& other){
    if(&other != this){
        Property::operator=(other);
        this->setFloor(other.floor);
    }
    return *this;
}

bool Apartment::operator==(const Apartment& other){
    return Property::operator==(other) && this->floor == other.floor;
}

std::string Apartment::toString(bool forFile){
    std::string result;
    if(forFile){
        result =
                Property::toString(true) + " " +
                std::to_string(this->floor);
    } else {
        result =
                Property::toString() + " " +
                std::to_string(this->floor) + "floor";
    }
    return result;
}