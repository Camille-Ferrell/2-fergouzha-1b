/*
Project 1B: Camille, James, & Sebastian

This the file contains the implementaiton fo the Code class
It has two constructors to initialize the Code objects with specified length and range, adn with a given guess
It has the function that initialize the secret code
It has the check correct and check incorrect functions
It has a print secret code function
It has a getLength function, and lastly a getSecretCode function to return the secret code as a constant reference
*/

#include "Code.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Constructor to initialize the Code object with specified length (n) and range (m)
Code::Code(int n, int m) {
    this->n = n; // set the length of the code
    this->m = m; // set the range of the digits
}

// constructor to initialize the Code object with a given guess
Code::Code(const vector<int>& guess) {
    this->secret_code = guess; // set the secret code to the provided guess
    this->n = guess.size(); // set the length of the code based on the guess
    this->m = 0; // Not used in this context, but initialized to 0
}

// function to randomly initialize the secret code
void Code::initialize_randomly() {
    secret_code.clear(); // clear an exisiting code
    for (int i = 0; i < n; ++i) {
        secret_code.push_back(rand() % m); // generate a random digit within the range and add it ot the secret code
    }
}

// function to check the number of correct digits in the correct positions
int Code::check_correct(const vector<int>& guess) const {
    int count = 0; // initialize the count of correct digits
    for (int i = 0; i < n; ++i) {
        if (guess[i] == secret_code[i]) {
            count++; // increment count if the digit mathces the secret code at the same position
        }
    }
    return count; // return the count of correct digits
}

// function to check the number of correct digits in incorrect positions
int Code::check_incorrect(const vector<int>& guess) const {
    int count = 0; // initialize count of the correct digits in incorrect positions
    vector<int> secret_copy = secret_code; // make a copy of the secret code to modify
    for (int i = 0; i < n; ++i) {
        // find the guess digits in the copy of the secret code
        auto it = find(secret_copy.begin(), secret_copy.end(), guess[i]);
        if (it != secret_copy.end()) {
            count++; // increment count if the digit it found
            secret_copy.erase(it); // remove the mathced digit from the copy
        }
    }
    count -= check_correct(guess); // substract the count of correct digits in correct positions to get only incorrect positions
    return count; // return the count of correct digits in incorrect positions
}

// function to print the secret code to the console
void Code::print_secret_code() const {
    cout << "Secret Code: ";
    for (int digit : secret_code) {
        cout << digit << " "; // print each digit of the secret code
    }
    cout << endl;
}

// function to ge tthe length of the code
int Code::getLength() const {
    return n; // return length of the code
}

// function to get the secret code
const vector<int>& Code::getSecretCode() const {
    return secret_code; // return the secret code as a constant reference
}
