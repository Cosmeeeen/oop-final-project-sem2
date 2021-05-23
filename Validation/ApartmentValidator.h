#pragma once
#include "ValidationException.h"
#include "PropertyValidator.h"

class ApartmentValidator : public PropertyValidator{
public:
    ApartmentValidator();
    ~ApartmentValidator();
    void validate(Property* p) throw(ValidationException);
};