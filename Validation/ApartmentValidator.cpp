#include "ApartmentValidator.h"
#include "../Entities/Apartment.h"

ApartmentValidator::ApartmentValidator() = default;

ApartmentValidator::~ApartmentValidator() = default;


void ApartmentValidator::validate(Property* p) throw(ValidationException){
    string errorMessage = "";

    try{
        PropertyValidator::validate(p);
    }catch(ValidationException& e){
        errorMessage += e.toString();
    }

    Apartment* a = (Apartment*) p;
    if(a->getFloor() < 0){
        errorMessage += "Floor number can't be negative.\n";
    }

    if(errorMessage.length() > 0){
        throw ValidationException(errorMessage);
    }
}