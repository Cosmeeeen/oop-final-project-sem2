#include "Service.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include "../Validation/RepoException.h"
#include "../Validation/ValidationException.h"

using namespace std;

Service::Service(){

}

Service::Service(Repo* repo){
    this->repo = repo;
}

Service::~Service(){

}

void Service::addHouse(int id, int surface, int rooms, int price, string street, int floors) throw(RepoException, ValidationException){
    House* h = new House(
        id,
        surface,
        rooms,
        price,
        street,
        floors
    );
    this->repo->addProperty(h);
}

void Service::addApartment(int id, int surface, int rooms, int price, string street, int floor) throw(RepoException, ValidationException){
    Apartment* a = new Apartment(
        id,
        surface,
        rooms,
        price,
        street,
        floor
    );
    this->repo->addProperty(a);
}

void Service::updateHouse(int oldId, int newId, int surface, int rooms, int price, string street,int floors) throw(class RepoException, class ValidationException) {
    House* oldH = new House(oldId, 0,0,0,"a",0);
    House* newH = new House(
        newId,
        surface,
        rooms,
        price,
        street,
        floors
    );
    this->repo->updateProperty(oldH, newH);
}

void Service::updateApartment(int oldId, int newId, int surface, int rooms, int price, string street, int floors) throw(class RepoException, class ValidationException) {
    Apartment* oldA = new Apartment(oldId, 0,0,0,"a",0);
    Apartment* newA = new Apartment(
        newId,
        surface,
        rooms,
        price,
        street,
        floors
    );
    this->repo->updateProperty(oldA, newA);
}

void Service::deleteProperty(int id) {
    auto properties = this->repo->getAll();
    for(int i = 0; i<this->repo->getSize(); i++){
        if(properties[i]->getId() == id){
            this->repo->deleteProperty(properties[i]);
            return;
        }
    }
}

vector<Property*> Service::getAll(){
    return this->repo->getAll();
}
