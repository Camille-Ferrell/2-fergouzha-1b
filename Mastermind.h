/*
Project 1B: Camille, James, & Sebastian

This file contains the definition of the Mastermind CLass which handles the playing of the game
The file just contains each function that is implemented in the Mastermind.cpp file
*/

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "Code.h"
#include "Response.h"

class Mastermind {
private:
    Code secret_code;

public:
    Mastermind(int n, int m); // constructor with parameters

    Mastermind(); // default constructor

    void printSecretCode() const; // function to print the secret code

    Code humanGuess() const; // function to read a guess from the keyboard

    Response getResponse(const Code& guess) const; // function to get the response

    bool isSolved(const Response& response) const; // function to check if the game is solved

    void playGame(); // function to play the game
};

#endif // MASTERMIND_H
