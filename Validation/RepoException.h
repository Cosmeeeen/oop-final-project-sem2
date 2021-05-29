#pragma once
#include <exception>
#include <string>

using namespace std;

class RepoException : public runtime_error{
private:
    char* message;
public:
    RepoException(char* msg) : runtime_error(msg), message(msg){

    }

    const char* what(){
        return this->message;
    }
};