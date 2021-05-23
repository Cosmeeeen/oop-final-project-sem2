#pragma once
#include <string>

class Property{
protected:
    int id;
    int surface;
    int rooms;
    int price;
    std::string street;
public:
    Property();
    Property(Property& other);
    Property(int id, int surface, int rooms, int price, std::string street);
    explicit Property(int id);
    virtual ~Property();

    virtual Property* clone();

    int getId() const;
    int getSurface() const;
    int getRooms() const;
    int getPrice() const;
    std::string getStreet() const;

    void setId(int newId);
    void setSurface(int newSurface);
    void setRooms(int newRooms);
    void setPrice(int newPrice);
    void setStreet(std::string newAddress);

    Property& operator=(const Property& other);
    bool operator==(const Property& other);

    virtual std::string toString(bool forFile = false);

};