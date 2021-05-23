#pragma once
#include <exception>
#include <string>

using namespace std;

class ValidationException{
private:
    string message;
public:
    ValidationException(string msg) : message(msg){

    }

    string toString(){
        return message;
    }
};