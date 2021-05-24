#include "PropertyValidator.h"
#include "ValidationException.h"

PropertyValidator::PropertyValidator() = default;

PropertyValidator::~PropertyValidator() = default;

void PropertyValidator::validate(Property* p) throw(ValidationException){
    string errorMessage = "";

    if(p->getRooms() < 0){
        errorMessage += "Number of rooms can't be negative.\n";
    }

    if(p->getSurface() < 0){
        errorMessage += "Surface area can't be negative.\n";
    }

    if(p->getPrice() < 0){
        errorMessage += "Price can't be negative.\n";
    }

    for(auto & it : p->getStreet()){
        if(isspace(it)){
            errorMessage += "Street name can't contain spaces.\n";
            break;
        }
    }

    if(errorMessage.length() > 0){
        throw ValidationException(errorMessage);
    }
}