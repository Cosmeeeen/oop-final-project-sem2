#include "Property.h"
#include <string>

Property::Property(){
    this->id = 0;
    this->surface = 0;
    this->rooms = 0;
    this->price = 0;
    this->street.clear();
}

Property::Property(Property& other){
    this->id = other.id;
    this->surface = other.surface;
    this->rooms = other.rooms;
    this->price = other.price;
    this->street = other.street;
}

Property::Property(int id, int surface, int rooms, int price, std::string street){
    this->id = id;
    this->surface = surface;
    this->rooms = rooms;
    this->price = price;
    this->street = street;
}

Property::Property(int id){
    this->id = id;
    this->surface = 0;
    this->rooms = 0;
    this->price = 0;
}

Property::~Property(){
    this->id = 0;
    this->surface = 0;
    this->price = 0;
    this->rooms = 0;
    this->street.clear();
}

Property* Property::clone(){
    return new Property(
        this->id,
        this->surface,
        this->rooms,
        this->price,
        this->street
    );
}

int Property::getId() const{
    return this->id;
}

int Property::getSurface() const{
    return this->surface;
}

int Property::getRooms() const{
    return this->rooms;
}

int Property::getPrice() const{
    return this->price;
}

std::string Property::getStreet() const {
    return this->street;
}

void Property::setId(int newId){
    this->id = newId;
}

void Property::setSurface(int newSurface){
    this->surface = newSurface;
}

void Property::setRooms(int newRooms){
    this->rooms = newRooms;
}

void Property::setPrice(int newPrice){
    this->price = newPrice;
}

void Property::setStreet(std::string newAddress){
    this->street = std::move(newAddress);
}

Property& Property::operator=(const Property &other) = default;

bool Property::operator==(const Property &other){
    return (
        this->id == other.id &&
        this->surface == other.surface &&
        this->rooms == other.rooms &&
        this->price == other.price &&
        this->street == other.street
    );
}

std::string Property::toString(bool forFile){
    std::string result;

    if(forFile){
        // The P in front shows that the object is a property
        result =
                std::to_string(this->id) + " " +
                std::to_string(this->surface) + " " +
                std::to_string(this->rooms) + " " +
                std::to_string(this->price) + " " +
                this->street;
    } else {
        result =
            std::to_string(this->id) + ". " +
            std::to_string(this->surface) + "m3 " +
            std::to_string(this->rooms) + "rooms " +
            std::to_string(this->price) + "eur " +
            this->street;
    }
    return result;
}