#include "RepoTester.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include "../Repository/Repo.h"
#include "../Validation/RepoException.h"
#include <cassert>
#include <iostream>

void RepoTester::testGetAll(){
    Repo repo;
    for(auto & property : this->properties){
        repo.addProperty(property);
    }

    vector<Property*> properties = repo.getAll();
    assert(properties.size() == this->properties.size());
    for(int i=0; i<this->properties.size(); i++){
        assert(*properties[i] == *this->properties[i]);
    }
}

void RepoTester::testGetSize(){
    Repo repo;
    assert(repo.getSize() == 0);

    for(auto & propertie : this->properties){
        repo.addProperty(propertie);
    }

    assert(repo.getSize() == this->properties.size());
}

void RepoTester::testGet(){
    Repo repo;
    for(auto & property : this->properties){
        repo.addProperty(property);
    }

    vector<Property*> properties = repo.getAll();
    for(int i=0; i<this->properties.size(); i++){
        assert(*repo.get(i) == *this->properties[i]);
    }

    try{
        repo.get(-1);
        assert(false);
    }catch(RepoException &e) {

    } catch(...) {
        assert(false);
    }

    try{
        repo.get(repo.getSize());
        assert(false);
    } catch(RepoException &e) {
    } catch(...) {
        assert(false);
    }
}

void RepoTester::testFind(){
    Repo repo;
    for(auto &property : this->properties){
        repo.addProperty(property);
    }

    for(int i=0; i<this->properties.size(); i++){
        assert(repo.find(this->properties[i]) == i);
    }

    House* h1 = new House(
            1,
            100,
            100,
            100,
            "abc",
            100
            );
    assert(repo.find(h1) == -1);
}

void RepoTester::testAddProperty() {
    Repo repo;
    for(auto & property : this->properties){
        repo.addProperty(property);
    }

    House* h1 = new House(
            100,
            100,
            100,
            100,
            "abc",
            100
            );
    repo.addProperty(h1);
    assert(repo.getSize() == this->properties.size() + 1);
    assert(*repo.get(repo.getSize() - 1) == *h1);
}

void RepoTester::testUpdateProperty(){
    Repo repo;
    for(auto & property : this->properties){
        repo.addProperty(property);
    }

    House* h1 = new House(
            1,
            100,
            100,
            100,
            "abc",
            100
            );
    House* h2 = new House(
            2,
            200,
            200,
            200,
            "def",
            200
            );
    repo.updateProperty(this->properties[1], h1);
    assert(repo.find(this->properties[1]) == -1);
    assert(repo.find(h1) != -1);
    try {
        repo.updateProperty(this->properties[1], h2);
    } catch(RepoException& e){
    } catch(...){
        assert(false);
    }

    assert(repo.find(h1) != -1);
    assert(repo.find(h2) == -1);
}

void RepoTester::testDeleteProperty() {
    Repo repo;
    for(auto & property : this->properties) {
        repo.addProperty(property);
    }

    repo.deleteProperty(this->properties[0]);
    assert(repo.getSize() == 1);
    assert(repo.find(this->properties[1]) != -1);

    House* h1 = new House(
            1,
            100,
            100,
            100,
            "abc",
            100
            );
    try{
        repo.deleteProperty(h1);
    }catch(RepoException& e){
    }catch(...){
        assert(false);
    }
    assert(repo.getSize() == 1);
    assert(repo.find(this->properties[1]) != -1);
}

RepoTester::RepoTester(){
    House* h = new House(
            10,
            100,
            5,
            1000,
            "abc",
            1
            );
    Apartment* a = new Apartment(
            20,
            50,
            3,
            500,
            "def",
            3
            );
    this->properties.push_back(h);
    this->properties.push_back(a);
}

RepoTester::~RepoTester(){
    for(auto & property : this->properties){
        delete property;
        property = nullptr;
    }
    this->properties.clear();
}

void RepoTester::runAll(){
    this->testGetAll();
    this->testGetSize();
    this->testGet();
    this->testFind();
    this->testAddProperty();
    this->testUpdateProperty();
    this->testDeleteProperty();
}