#include "RepoFile.h"
#include <fstream>
#include "../Entities/House.h"
#include "../Entities/Apartment.h"
#include "../Validation/RepoException.h"
#include "../Validation/ValidationException.h"
#include "../Validation/ReadFromFileException.h"

RepoFile::RepoFile(string filename){
    this->fileName = filename;
    this->loadFromFile();
}

RepoFile::~RepoFile() {}

void RepoFile::setFileName(string fileName){
    this->fileName = fileName;
}

void RepoFile::addProperty(Property* p) throw(RepoException, ValidationException){
    Repo::addProperty(p);
    this->saveToFile();
}

void RepoFile::updateProperty(Property* oldP, Property* newP) throw(RepoException, ValidationException){
    Repo::updateProperty(oldP, newP);
    this->saveToFile();
}

void RepoFile::deleteProperty(Property* p) throw(RepoException, ValidationException){
    Repo::deleteProperty(p);
    this->saveToFile();
}

void RepoFile::loadFromFile(){
    ifstream f(this->fileName);
    if(f.is_open()){
        this->empty();
        string line;
        string sep = " ";

        try{
            while(getline(f, line)){
                if(line.substr(0, 1) == "H"){
                    line = line.erase(0, 2);

                    int pos = line.find(sep);
                    int id = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int surface = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int rooms = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int price = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    string street = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    int floors = stoi(line);

                    House* h = new House(
                        id,
                        surface,
                        rooms,
                        price,
                        street,
                        floors
                    );
                    this->houseValidator.validate(h);
                    this->properties.push_back(h);
                }else if(line.substr(0, 1) == "A"){
                    line = line.erase(0, 2);

                    int pos = line.find(sep);

                    int id = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int surface = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int rooms = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    int price = stoi(line.substr(0, pos));
                    line = line.erase(0, pos + 1);

                    pos = line.find(sep);
                    string street = line.substr(0, pos);
                    line = line.erase(0, pos + 1);

                    int floor = stoi(line);

                    Apartment* a = new Apartment(
                        id,
                        surface,
                        rooms,
                        price,
                        street,
                        floor
                    );
                    this->apartmentValidator.validate(a);
                    this->properties.push_back(a);
                }
            }
        } catch (...) {
            throw ReadFromFileException("Invalid formatting in file data.");
        }
        f.close();
    }else{
        throw ReadFromFileException("File does not exist!");
    }
}

void RepoFile::saveToFile() {
    ofstream f(this->fileName);
    if(f.is_open()){
        for(auto & property : this->properties){
            f << property->toString(true) << '\n';
        }
    }
}