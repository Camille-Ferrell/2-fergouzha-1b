/*
Project 1B: Camille, James, & Sebastian

This file contains the implementation of the Mastermind class
It has the two constructors, one withe the passed values, and one with no parameters
It has a function that prints the secret code
It has a function that read the guess from the keyboard
It has a function that returns a reponse to the guess
It has a function that determines whether or not the game has been solved
It has a funciton that essentially plays the game
*/

#include "Mastermind.h"
#include <iostream>

using namespace std;

// constructor that initializes the game with specifide code length and digit range
Mastermind::Mastermind(int n, int m) : secret_code(n, m) {
    secret_code.initialize_randomly(); // initialize the secret code randomly
}

// default constructor that initializes the game with default values
Mastermind::Mastermind() : secret_code(5, 10) {
    secret_code.initialize_randomly(); // initialize the secret code randomly
}

// function to print the secret code to the console
void Mastermind::printSecretCode() const {
    secret_code.print_secret_code();
}

// function to get guess from the user
Code Mastermind::humanGuess() const {
    int n = secret_code.getLength(); // get the length of the code
    vector<int> guess(n); // create a vector to store the user's guess
    cout << "Enter your guess of length " << n << ": ";
    for (int i = 0; i < n; ++i) {
        cin >> guess[i]; // read each digit of the guess from the user
    }
    return Code(guess); // return the guess as a Code object
}

// function to get the reponse (correct and incorrect digits) for a given guess
Response Mastermind::getResponse(const Code& guess) const {
    int correct = secret_code.check_correct(guess.getSecretCode()); // check how many digits are correct and in the correct position
    int incorrect = secret_code.check_incorrect(guess.getSecretCode()); // check how many digits are correct but in the wrong position
    return Response(correct, incorrect); // return the response as a Response object
}

// funciton to check if the game is solved
bool Mastermind::isSolved(const Response& response) const {
    return response.getCorrect() == secret_code.getLength(); // check if the number of correct digits matches the length of the secret code
}

//function to play the game
void Mastermind::playGame() {
    printSecretCode(); // print the secret code for testing purposes
    for (int attempt = 1; attempt <= 10; ++attempt) { // allow up to 10 attemtps
        cout << "Attempt " << attempt << endl;
        Code guess = humanGuess(); // get the user's guess
        Response response = getResponse(guess); // get the response for the guess
        cout << response << endl; // print the response
        if (isSolved(response)) { // chcek if the game is solved
            cout << "Congratulations! You guessed the code correctly!" << endl;
            return; // end the game if the code is guessed correctly
        }
    }
    // if the code is not guesses correctly within 10 attemtps, print failure messageand the correct code
    cout << "Sorry, you did not guess the code within 10 attempts. The correct code was: ";
    printSecretCode();
}
