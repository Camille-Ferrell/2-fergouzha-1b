#include "Mastermind.h"
#include <iostream>

using namespace std;

Mastermind::Mastermind(int n, int m) : secretCode(n, m), maxGuesses(10), currentGuesses(0), nVal(n), mVal(m) {
    // Initialize the Mastermind game with the given parameters
}

Mastermind::Mastermind() : secretCode(5, 10), maxGuesses(10), currentGuesses(0), nVal(5), mVal(10) {
    // Initialize the Mastermind game with default parameters
}

void Mastermind::printSecretCode() const {
    // Print the secret code to the screen
    secretCode.printSecretCode();
}
Code Mastermind::humanGuess() const {
    // Read a guess from the keyboard and return it as a Code object

    //variables to track the entered digit and its validity
    int bufDigit;
    bool inputValid = false;
    //vector to store digits of a guess
    vector<int> bufGuess;

    //iterates n times (one-indexed) to receive and validate every input
    for (int i = 1; i <= nVal; i++) {
        //prompts the user for input and loops back if the input is invalid
        while (!inputValid) {
            cout << "Guess Digit (" << i << "/" << nVal << "): ";
            cin >> bufDigit;

            //checks for an invalid input
            //inputs must be accepted by bufDigit and be between 0 and mVal
            if (cin.fail() || (bufDigit < 0) || (bufDigit >= mVal)) {
                cout << "Invalid input! Guesses must be positive integers less than " << mVal << "." << endl;
                inputValid = false;
            }
            else
                //if the input is valid, the while-loop is allowed to exit
                inputValid = true;
        }
        //resets inputValid and stores bufDigit as part of the current guess
        inputValid = false;
        bufGuess.push_back(bufDigit);
    }
    //generates and returns a Code object with the user-inputted digits
    Code guess(nVal, mVal, bufGuess);
    return guess;
}

Response Mastermind::getResponse(const Code& guess) {
    // Get the response for the given guess using the secretCode
    int c, i;
    c = secretCode.checkCorrect(guess);
    i = secretCode.checkIncorrect(guess);
    Response response(c, i);
    return response;
}

bool Mastermind::isSolved(const Response& response) const {
    //returns true if the number of correct digits equals n, else returns false
    if (response.getNumCorrect() == nVal)
        return true;
    else
        return false;
}

void Mastermind::playGame() {
    // Initialize a random secret code and print it
    // Implement the game loop, taking guesses from the user and providing responses
    // Check for a win or loss condition in each iteration

    //tracks whether the code has been solved
    bool solved = false;

    Response bufResponse(0, 0);

    //reset guess count
    currentGuesses = 0;

    //announces game start and secret code (for testing purposes)
    cout << "Starting Mastermind" << endl;
    cout << "Secret Code: ";
    printSecretCode();
    cout << endl;

    //game loop - repeats until guesses run out or the code is solved
    while ((currentGuesses < maxGuesses) && !solved) {
        //announces number of guesses submitted and maximum guesses allowed
        cout << "Round " << (currentGuesses + 1) << " of " << maxGuesses << endl;

        //receives a guess from the user, then generates and prints response
        bufResponse = getResponse(humanGuess());
        cout << bufResponse << endl;

        //checks if the response indicates the code is solved
        if (isSolved(bufResponse))
            solved = true;

        //increments guess count
        currentGuesses++;
    }

    //prints appropriate win/loss message
    if (solved)
        cout << "You solved the code in " << currentGuesses << " guess(es)!"
        << endl;
    else {
        cout << "You lost! Secret code: ";
        printSecretCode();
        cout << endl;
    }

}