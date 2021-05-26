#pragma once
#include "../Repository/RepoFile.h"

class RepoFileTester {
private:
    const string fileName = "testProducsIn.txt";
    const string fileNameOut = "testProducsOut.txt";
    const string fileNameInvalid = "testInvalidProducts.txt";

    vector<Property*> properties;

    void testAddProperty();
    void testUpdateProperty();
    void testDeleteProperty();

    void testLoadFromFile();
    void testSaveFromFile();
public:
    RepoFileTester();
    ~RepoFileTester();
    void testAll();
};