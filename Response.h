/*
Project 1B: Camille, James, & Sebastian

This file contains the definition of the Response class
It contains all of the functions that are implemented in the Response.cpp file
*/

#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>

using namespace std;

class Response {
private:
    int correct;
    int incorrect;

public:
    Response(int correct = 0, int incorrect = 0); // constructor

    void setCorrect(int c); // set correct value

    void setIncorrect(int ic); // set incorrect value

    int getCorrect() const; // get correct value

    int getIncorrect() const; // get incorrect value

    bool operator==(const Response& other) const; // overload == operator

    friend ostream& operator<<(ostream& os, const Response& response); // overload << operator
};

#endif // RESPONSE_H
