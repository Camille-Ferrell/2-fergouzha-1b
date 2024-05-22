/*
Prject 1B: Camille, James, & Sebastian

This file contains the implementation of the Response class
It contains the set and get functions to set and get the number of correct and incorrect guesses
It also contains the overloaded == and << functions to compare and print Response objects
*/

#include "Response.h"

// Constructor to initialize the Response object with the number of correct and incorrect guesses
Response::Response(int correct, int incorrect) {
    this->correct = correct; // set the correct count
    this->incorrect = incorrect; // set the incorrect count
}

// function to set the number of correct guesses
void Response::setCorrect(int c) {
    correct = c;
}

// function to set the number of incorrect guesses
void Response::setIncorrect(int ic) {
    incorrect = ic;
}

// function to get the number of correct guesses
int Response::getCorrect() const {
    return correct;
}

// function to get teh nuber of incorrect guesses
int Response::getIncorrect() const {
    return incorrect;
}

// overloaded equality operatr to compare two Response objects
bool Response::operator==(const Response& other) const {
    // return true if both the correct and incorrect counts are equal
    return (correct == other.correct && incorrect == other.incorrect);
}

// overloaded insertion operator to print a Reponse object
ostream& operator<<(ostream& os, const Response& response) {
    // print the number of correct and incorrect guesses
    os << "Correct: " << response.correct << ", Incorrect: " << response.incorrect;
    return os;
}
