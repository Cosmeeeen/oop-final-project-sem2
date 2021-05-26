#pragma once
#include "Repo.h"

class RepoFile : public Repo{
private:
    string fileName;
public:
    RepoFile(string fileName);
    ~RepoFile();

    void setFileName(string fileName);

    void addProperty(Property* p) throw(RepoException, ValidationException);
    void updateProperty(Property* oldP, Property* newP) throw(RepoException, ValidationException);

    void deleteProperty(Property* p) throw(RepoException, ValidationException);

    void loadFromFile();
    void saveToFile();
};