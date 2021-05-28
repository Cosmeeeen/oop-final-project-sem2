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
public:
    UI(Service service);
    ~UI();

    void runUI();
};