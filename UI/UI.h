#pragma once
#include "../Service/Service.h"


class UI{
private:
    Service service;
    void printMenu();

    void handleAddHouse();
    void handleAddApartment();

    void handleEditHouse();
    void handleEditApartment();

    void handleDeleteProperty();
    void handleShowAll();

    void handleGetMostValuable();
    void handleGetSorted();
    void handleGetByRooms();
public:
    UI(Service service);
    ~UI();

    void runUI();
};