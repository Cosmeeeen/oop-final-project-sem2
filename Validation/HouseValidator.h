#pragma once
#include "ValidationException.h"
#include "PropertyValidator.h"

class HouseValidator : public PropertyValidator{
public:
    HouseValidator();
    ~HouseValidator();
    void validate(Property* p) throw(ValidationException);
};
