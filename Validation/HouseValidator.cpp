#include "HouseValidator.h"
#include "../Entities/House.h"

HouseValidator::HouseValidator() = default;

HouseValidator::~HouseValidator() = default;

void HouseValidator::validate(Property *p) throw(ValidationException){
    string errorMessage = "";

    try{
        PropertyValidator::validate(p);
    }catch(ValidationException& e){
        errorMessage += e.toString();
    }

    House* h = (House*)p;
    if(h->getFloors() < 0){
        errorMessage += "Number of floors can't be negative.\n";
    }

    if(errorMessage.length() > 0){
        throw ValidationException(errorMessage);
    }
}