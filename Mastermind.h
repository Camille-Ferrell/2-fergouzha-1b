#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "Code.h"
#include "Response.h"

class Mastermind {
private:
    Code secretCode;
    int maxGuesses;
    int currentGuesses;
    int nVal;
    int mVal;

public:
    Mastermind(int n, int m);       // constructor for custom n and m values
    Mastermind();                   // constructor for default n and m values (5 and 10)
    void printSecretCode() const;   // prints secret code (debug feature specified by rubric)
    Code humanGuess() const;        // prompts user for guess, validates input, 
    Response getResponse(const Code& guess);
    bool isSolved(const Response& response) const;
    void playGame();
};

#endif // MASTERMIND_H


