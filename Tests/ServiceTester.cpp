#include "ServiceTester.h"
#include "../Service/Service.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include "../Validation/RepoException.h"
#include "../Repository/Repo.h"
#include <vector>
#include <cassert>

void ServiceTester::testGetAll(){
    Repo* repo = new Repo();
    Service serv(repo);

    House* h = new House(
        100,
        100,
        100,
        100,
        "a",
        100
    );
    Apartment* a = new Apartment(
        200,
        200,
        200,
        200,
        "a",
        200
    );
    serv.addHouse(
        h->getId(),
        h->getSurface(),
        h->getFloors(),
        h->getPrice(),
        h->getStreet(),
        h->getFloors()
    );
    serv.addApartment(
        a->getId(),
        a->getSurface(),
        a->getRooms(),
        a->getPrice(),
        a->getStreet(),
        a->getFloor()
    );
    vector<Property*> properties = serv.getAll();
    assert(*properties[0] == *h);
    assert(*properties[1] == *a);
}

void ServiceTester::testAddHouse() {
    Repo* repo = new Repo();
    Service serv(repo);

    House* h = new House(
        100,
        100,
        100,
        100,
        "a",
        100
    );

    serv.addHouse(h->getId(), h->getSurface(), h->getRooms(), h->getPrice(), h->getStreet(), h->getFloors());
    assert(*serv.getAll()[0] == *h);
}

void ServiceTester::testAddApartment() {
    Repo* repo = new Repo();
    Service serv(repo);

    Apartment* a = new Apartment(
            200,
            200,
            200,
            200,
            "a",
            200
    );

    serv.addApartment(a->getId(), a->getSurface(), a->getRooms(), a->getPrice(), a->getStreet(), a->getFloor());
    assert(*serv.getAll()[0] == *a);
}

void ServiceTester::testUpdateHouse() {
    Repo* repo = new Repo();
    Service serv(repo);

    House* h1 = new House(
        100,
        100,
        100,
        100,
        "a",
        100
    );
    serv.addHouse(h1->getId(), h1->getSurface(), h1->getRooms(), h1->getPrice(), h1->getStreet(), h1->getFloors());

    House* h2 = new House(
        200,
        200,
        200,
        200,
        "b",
        200
    );
    serv.updateHouse(h1->getId(), h2->getId(), h2->getSurface(), h2->getRooms(), h2->getPrice(), h2->getStreet(), h2->getFloors());
    assert(*serv.getAll()[0] == *h2);

    House* h3 = new House(
        300,
        300,
        300,
        300,
        "c",
        300
    );

    try{
        serv.updateHouse(h3->getId(), h2->getId(), h2->getSurface(), h2->getRooms(), h2->getPrice(), h2->getStreet(), h2->getFloors());
        assert(false);
    }catch(RepoException& e){

    }catch(...){
        assert(false);
    }
}

void ServiceTester::testUpdateApartment() {
    Repo* repo = new Repo();
    Service serv(repo);

    Apartment* a1 = new Apartment(
            100,
            100,
            100,
            100,
            "a",
            100
    );
    serv.addApartment(a1->getId(), a1->getSurface(), a1->getRooms(), a1->getPrice(), a1->getStreet(), a1->getFloor());

    Apartment* a2 = new Apartment(
            200,
            200,
            200,
            200,
            "b",
            200
    );
    serv.updateApartment(a1->getId(), a2->getId(), a2->getSurface(), a2->getRooms(), a2->getPrice(), a2->getStreet(), a2->getFloor());
    assert(*serv.getAll()[0] == *a2);

    Apartment* a3 = new Apartment(
            300,
            300,
            300,
            300,
            "c",
            300
    );

    try{
        serv.updateApartment(a3->getId(), a2->getId(), a2->getSurface(), a2->getRooms(), a2->getPrice(), a2->getStreet(), a2->getFloor());
        assert(false);
    }catch(RepoException& e){

    }catch(...){
        assert(false);
    }
}

void ServiceTester::testDeleteProperty() {
    Repo* repo = new Repo();
    Service serv(repo);

    House* h = new House(
        100,
        100,
        100,
        100,
        "a",
        100
    );

    serv.addHouse(h->getId(), h->getSurface(), h->getRooms(), h->getPrice(), h->getStreet(), h->getFloors());

    serv.deleteProperty(10);
    vector<Property*> properties = serv.getAll();
    assert(properties.size() == 1);
    serv.deleteProperty(h->getId());
    properties = serv.getAll();
    assert(properties.empty());
}

ServiceTester::ServiceTester() {}

ServiceTester::~ServiceTester() {}

void ServiceTester::runAll(){
    this->testGetAll();
    this->testAddHouse();
    this->testAddApartment();
    this->testUpdateHouse();
    this->testUpdateApartment();
    this->testDeleteProperty();
}