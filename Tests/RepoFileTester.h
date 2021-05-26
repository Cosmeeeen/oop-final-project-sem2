#pragma once
#include "../Repository/RepoFile.h"

class RepoFileTester {
private:
    const string fileName = "testProductsIn.txt";
    const string fileNameOut = "testProductsOut.txt";
    const string fileNameInvalid = "testInvalidProducts.txt";

    vector<Property*> properties;

    void testAddProperty();
    void testUpdateProperty();
    void testDeleteProperty();

    void testLoadFromFile();
    void testSaveToFile();
public:
    RepoFileTester();
    ~RepoFileTester();
    void runAll();
};