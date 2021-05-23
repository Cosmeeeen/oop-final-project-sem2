#include "../Entities/Property.h"
#include "../Entities/House.h"
#include "../Entities/Apartment.h"

class EntitiesTester{
private:
    Property testProperty;
    House testHouse;
    Apartment testApartment;

    void constructorsTests();
    void settersTest();
    void operatorsTests();
    void toStringTests();

public:
    EntitiesTester();
    ~EntitiesTester();

    void runAllTests();
};