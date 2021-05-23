#pragma once
#include "../Entities/Property.h"
#include "ValidationException.h"

class PropertyValidator{
public:
    PropertyValidator();
    ~PropertyValidator();

    void validate(Property* p) throw(ValidationException);
};