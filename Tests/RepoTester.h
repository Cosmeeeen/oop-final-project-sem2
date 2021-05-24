#pragma once
#include "../Entities/Property.h"
#include <vector>

using namespace std;

class RepoTester{
private:
    vector<Property*> properties;
    void testGetAll();
    void testGetSize();
    void testGet();
    void testFind();
    void testAddProperty();
    void testUpdateProperty();
    void testDeleteProperty();
public:
    RepoTester();
    ~RepoTester();
    void runAll();
};