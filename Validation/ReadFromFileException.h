#pragma once
#include <exception>
#include <string>

using namespace std;

class ReadFromFileException : public exception{
private:
    // Used to be char*
    // Change back here if any errors
    string message;
public:
    ReadFromFileException(string message){
        // also uncomment this and change parameter

        //this->message = new char[strlen(message) + 1];
        //strlcpy(this->message, message, strlen(message));
    }

    ~ReadFromFileException(){
        // and uncomment this too

        //if(this->message != nullptr){
        //    delete[] this->message;
        //}
    }

    // also change here
    virtual string what(){
        return message;
    }

};