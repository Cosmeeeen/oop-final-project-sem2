#include "RepoFileTester.h"
#include <cassert>
#include "../Repository/Repo.h"
#include "../Entities/Property.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include "../Validation/RepoException.h"
#include "../Validation/ReadFromFileException.h"

void RepoFileTester::testAddProperty() {
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);

    House* h = new House(
        300,
        300,
        300,
        300,
        "testStreetThree",
        300
    );

    repoFile.addProperty(h);
    assert(repoFile.getSize() == this->properties.size() + 1);
    assert(*repoFile.get(repoFile.getSize() - 1) == *h);
}

void RepoFileTester::testUpdateProperty(){
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    House* h1 = new House(
        300,
        300,
        300,
        300,
        "testStreetThree",
        300
    );
    House* h2 = new House(
        400,
        400,
        400,
        400,
        "testStreetFour",
        300
    );
    repoFile.updateProperty(this->properties[1], h1);
    assert(*repoFile.get(0) == *this->properties[0]);
    assert(*repoFile.get(1) == *h1);
    try{
        repoFile.updateProperty(this->properties[1], h2);
    }catch(RepoException& e){

    }catch(...){
        assert(false);
    }
    assert(*repoFile.get(0) == *this->properties[0]);
    assert(*repoFile.get(1) == *h1);
}

void RepoFileTester::testDeleteProperty(){
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    repoFile.deleteProperty(this->properties[0]);
    assert(repoFile.getSize() == 1);
    assert(*repoFile.get(0) == *this->properties[1]);
    House* h = new House(
        300,
        300,
        300,
        300,
        "testStreetThree",
        300
    );
    try{
        repoFile.deleteProperty(h);
    }catch(RepoException& e){

    }catch(...){
        assert(false);
    }
    assert(repoFile.getSize() == 1);
    assert(*repoFile.get(0) == *this->properties[1]);
}

void RepoFileTester::testLoadFromFile() {
    RepoFile repoFile = RepoFile(this->fileName);
    assert(repoFile.getSize() == this->properties.size());
    for(int i=0; i<this->properties.size(); i++){
        assert(*repoFile.get(i) == *this->properties[i]);
    }

    repoFile.setFileName("dalfksjvlkasjd.txt");
    try{
        repoFile.loadFromFile();
        assert(false);
    }catch(ReadFromFileException &e){

    }catch(...){
        assert(false);
    }

    repoFile.setFileName(this->fileNameInvalid);
    try{
        repoFile.loadFromFile();
        assert(false);
    }catch(ReadFromFileException& e){

    }catch(...){
        assert(false);
    }
}

void RepoFileTester::testSaveToFile() {
    RepoFile repoFile = RepoFile(this->fileName);
    repoFile.setFileName(this->fileNameOut);
    House* h = new House(
        300,
        300,
        300,
        300,
        "testStreetThree",
        300
    );

    repoFile.addProperty(h);
    repoFile.saveToFile();
    repoFile.loadFromFile();
    assert(repoFile.getSize() == this->properties.size() + 1);
    vector<Property*> properties = repoFile.getAll();
    for(int i=0; i<repoFile.getSize() - 1; i++){
        assert(*properties[i] == *this->properties[i]);
    }
    assert(*properties[properties.size() - 1] == *h);
}

RepoFileTester::RepoFileTester(){
    House* h = new House(
        100,
        100,
        100,
        100,
        "testStreetOne",
        100
    );
    Apartment* a = new Apartment(
        200,
        200,
        200,
        200,
        "testStreetTwo",
        200
    );

    this->properties.push_back(h);
    this->properties.push_back(a);
}

RepoFileTester::~RepoFileTester(){}

void RepoFileTester::runAll(){
    testAddProperty();
    testUpdateProperty();
    testDeleteProperty();

    testLoadFromFile();
    testSaveToFile();
}
