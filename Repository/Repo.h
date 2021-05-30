#pragma once
#include "../Entities/Property.h"
#include <vector>
#include "../Validation/HouseValidator.h"
#include "../Validation/ApartmentValidator.h"
#include "../Validation/RepoException.h"

class Repo{
protected:
    vector<Property*> properties;
    HouseValidator houseValidator;
    ApartmentValidator apartmentValidator;
public:
    Repo();
    ~Repo();

    vector<Property*> getAll();
    int getSize();
    Property* get(int index) throw(RepoException);
    int find(Property* p);

    virtual void addProperty(Property* p) throw(RepoException, ValidationException);
    virtual void updateProperty(Property* oldProperty, Property* newProperty) throw(RepoException, ValidationException);
    virtual void deleteProperty(Property* p) throw(RepoException);

    void empty();
};
