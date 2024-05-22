/*
Project 1B: Camille, James, & Sebastian

This file contains the definition of the Code class
It contains the function definitions of what's implemented in the Code.cpp file
*/

#ifndef CODE_H
#define CODE_H

#include <vector>
#include <iostream>

using namespace std;

class Code {
private:
    vector<int> secret_code;
    int n; // length
    int m; // range

public:
    Code(int n, int m); // constructor
    Code(const vector<int>& guess); // additional constructor for guesses

    void initialize_randomly(); // the function that initializes the secret code

    int check_correct(const vector<int>& guess) const; // check correct function passing only the guess as a parameter

    int check_incorrect(const vector<int>& guess) const; // check incorrect function

    void print_secret_code() const; // function to print the secret code

    int getLength() const; // function to get the length of the code

    const vector<int>& getSecretCode() const; // function to get the secret code
};

#endif // CODE_H
