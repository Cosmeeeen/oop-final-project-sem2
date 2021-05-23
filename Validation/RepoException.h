#pragma once
#include <exception>
#include <string>

using namespace std;

class RepoException : public runtime_error{
private:
    // Used to be char*
    // If any errors, change back here
    string message;
public:
    // also here
    RepoException(string msg) : runtime_error(msg), message(msg){

    }

    // and here
    const string what(){
        return message;
    }
};