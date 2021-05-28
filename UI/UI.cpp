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
    cout << "| dp | Delete a property    |\n";
    cout << "| sa | Show all properties  |\n";
    cout << "=============================\n";
    cout << "| q  | Exit the program     |\n";
    cout << "=============================\n";
}

void UI::handleAddHouse(){
    int id, surface, rooms, price, floors;
    string street;

    cout << "House ID: ";
    cin >> id;

    cout << "House surface: ";
    cin >> surface;

    cout << "Number of rooms: ";
    cin >> rooms;

    cout << "House price: ";
    cin >> price;

    cout << "Street name: ";
    cin >> street;

    cout << "Number of floors: ";
    cin >> floors;

    try{
        this->service.addHouse(
            id,
            surface,
            rooms,
            price,
            street,
            floors
        );
    }catch(ValidationException & e){
        cout << e.toString() << '\n';
    }catch(RepoException & e){
        cout << e.what() << '\n';
    }
}

void UI::handleAddApartment(){
    int id, surface, rooms, price, floor;
    string street;

    cout << "Apartment ID: ";
    cin >> id;

    cout << "Apartment surface: ";
    cin >> surface;

    cout << "Number of rooms: ";
    cin >> rooms;

    cout << "Apartment price: ";
    cin >> price;

    cout << "Street name: ";
    cin >> street;

    cout << "Floor number: ";
    cin >> floor;

    try{
        this->service.addApartment(
            id,
            surface,
            rooms,
            price,
            street,
            floor
        );
    }catch(ValidationException & e){
        cout << e.toString() << '\n';
    }catch(RepoException & e){
        cout << e.what() << '\n';
    }
}

void UI::handleEditHouse(){
    int oldId, newId, surface, rooms, price, floors;
    string street;

    cout << "Id of house to edit: ";
    cin >> oldId;

    cout << "New house id: ";
    cin >> newId;

    cout << "New house surface: ";
    cin >> surface;

    cout << "New number of rooms: ";
    cin >> rooms;

    cout << "New house price: ";
    cin >> price;

    cout << "New street name: ";
    cin >> street;

    cout << "New number of floors: ";
    cin >> floors;

    try{
        this->service.updateHouse(
            oldId,
            newId,
            surface,
            rooms,
            price,
            street,
            floors
        );
    }catch(ValidationException & e){
        cout << e.toString() << '\n';
    }catch(RepoException & e){
        cout << e.what() << '\n';
    }
}

void UI::handleEditApartment(){
    int oldId, newId, surface, rooms, price, floor;
    string street;

    cout << "Id of house to edit: ";
    cin >> oldId;

    cout << "New house id: ";
    cin >> newId;

    cout << "New house surface: ";
    cin >> surface;

    cout << "New number of rooms: ";
    cin >> rooms;

    cout << "New house price: ";
    cin >> price;

    cout << "New street name: ";
    cin >> street;

    cout << "New number of floors: ";
    cin >> floor;

    try{
        this->service.updateApartment(
            oldId,
            newId,
            surface,
            rooms,
            price,
            street,
            floor
        );
    }catch(ValidationException & e){
        cout << e.toString() << '\n';
    }catch(RepoException & e){
        cout << e.what() << '\n';
    }
}

void UI::handleDeleteProperty(){
    int toDelete;

    cout << "Id of property to delete: ";
    cin >> toDelete;

    try{
        this->service.deleteProperty(toDelete);
    }catch(ValidationException & e){
        cout << e.toString() << '\n';
    }catch(RepoException & e){
        cout << e.what() << '\n';
    }
}

void UI::handleShowAll(){
    vector<Property*> properties = service.getAll();
    if(properties.empty()){
        cout << "No properties saved.\n";
        return;
    }
    for(auto & it : properties){
        cout << it->toString() << '\n';
    }
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
        if(choice == "ah") {
            // add house
            this->handleAddHouse();
            cout << "Here\n";
        }else if(choice == "aa") {
            // add apartment
            this->handleAddApartment();
        }else if(choice == "eh") {
            // edit house
            this->handleEditHouse();
        }else if(choice == "ea") {
            // edit apartment
            this->handleEditApartment();
        }else if(choice == "dp") {
            // delete property
            this->handleDeleteProperty();
        }else if(choice == "sa") {
            // show all
            // todo repo edits not showing up
            this->handleShowAll();
        }else if(choice == "q"){
            break;
        }else{
            cout << "Invalid choice. Try again.\n";
        }
    }
}