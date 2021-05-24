#include "Repo.h"
#include "../Validation/RepoException.h"
#include "../Validation/ValidationException.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"

Repo::Repo() {}

Repo::~Repo(){
    this->empty();
}

vector<Property*> Repo::getAll(){
    vector<Property*> aux;

    for(auto & property : this->properties){
        aux.push_back(property->clone());
    }

    return aux;
}

int Repo::getSize(){
    return this->properties.size();
}

Property* Repo::get(int index) throw(RepoException){
    if(index < 0 || index >= this->properties.size()){
        throw RepoException("Invalid index.\n");
    }

    return this->properties[index]->clone();
}

int Repo::find(Property* p){
    for(int i=0; i<this->properties.size(); i++){
        if(*this->properties[i] == *p){
            return i;
        }
    }
    return -1;
}

void Repo::addProperty(Property *p) throw(RepoException, ValidationException){

    if(typeid(*p) == typeid(House)){
        this->houseValidator.validate(p);
    }

    if(typeid(*p) == typeid(Apartment)){
        this->apartmentValidator.validate(p);
    }

    if(this->find(p) != -1){
        throw RepoException("Property can't be added because it already exists.\n");
    }

    this->properties.push_back(p->clone());
}

void Repo::updateProperty(Property *oldProperty, Property *newProperty) throw(RepoException, ValidationException) {
    if(typeid(*newProperty) == typeid(House)){
        this->houseValidator.validate(newProperty);
    }

    if(typeid(*newProperty) == typeid(Apartment)){
        this->apartmentValidator.validate(newProperty);
    }

    for(auto & propertie : this->properties){
        if(propertie->getId() == oldProperty->getId()){
            delete propertie;
            propertie = newProperty->clone();
            return;
        }
    }

    throw RepoException("Property can't be updated because it does not exist.\n");
}

void Repo::deleteProperty(Property* p) throw(RepoException){
    bool found = false;
    for(int i=0; i<this->properties.size(); i++){
        if(**(this->properties.begin() + i) == *p){
            delete this->properties[i];
            this->properties.erase(this->properties.begin() + i);
            i--;
            found = true;
            break;
        }
    }
    if(!found){
        throw RepoException("Product can't be deleted because it does not exist.\n");
    }
}

void Repo::empty(){
    for(auto & property : this->properties){
        if(property != nullptr){
            delete property;
            property = nullptr;
        }
    }
    this->properties.clear();
}