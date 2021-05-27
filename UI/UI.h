#pragma once
#include "../Service/Service.h"


class UI{
private:
    Service service;
    void printMenu();
public:
    UI(Service service);
    ~UI();

    void runUI();
};