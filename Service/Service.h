#pragma once
#include "../Repository/Repo.h"
class Service{
private:
    Repo* repo;
public:
    Service();
    Service(Repo* repo);
    ~Service();

    void addHouse(
        int id,
        int surface,
        int rooms,
        int price,
        string street,
        int floors
    ) throw(RepoException, ValidationException);

    void addApartment(
        int id,
        int surface,
        int rooms,
        int price,
        string street,
        int floors
    ) throw(RepoException, ValidationException);

    void updateHouse(
        int oldId,
        int newId,
        int surface,
        int rooms,
        int price,
        string street,
        int floors
    ) throw(RepoException, ValidationException);

    void updateApartment(
        int oldId,
        int newId,
        int surface,
        int rooms,
        int price,
        string street,
        int floors
    ) throw(RepoException, ValidationException);

    void deleteProperty(int id);

    Property* getMostExpensive();

    vector<Property*> getSorted();

    vector<Property*> getByRooms(int rooms);

    vector<Property*> getAll();
};
