#include "UI.h"
#include <iostream>
#include <string>
using namespace std;

void UI::printMenu() {
    cout << "===========M=E=N=U===========\n";
    cout << "| ah | Add a House          |\n";
    cout << "| aa | Add an Apartment     |\n";
    cout << "| eh | Edit a House         |\n";
    cout << "| ea | Edit an Apartment    |\n";
    cout << "| q  | Exit the program     |\n";
    cout << "=============================\n";
}

UI::UI(Service service){
    this->service = service;
}

UI::~UI(){}

void UI::runUI(){
    while(true){
        this->printMenu();
        string choice;
        getline(cin, choice);
        if(choice == "ah"){
            // add house
            cout << "this will add a house";
        }else if(choice == "q"){
            break;
        }else{
            cout << "Invalid choice. Try again.\n";
        }
    }
}