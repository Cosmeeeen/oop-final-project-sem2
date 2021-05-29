#pragma once
#include <exception>
#include <string>

using namespace std;

class ReadFromFileException : public exception{
private:
    char* message;
public:
    ReadFromFileException(const char* message){
        this->message = new char[strlen(message) + 1];
        strlcpy(this->message, message, strlen(message));
    }

    ~ReadFromFileException(){
        if(this->message != nullptr){
            delete[] this->message;
        }
    }

    virtual const char* what(){
        return message;
    }

};