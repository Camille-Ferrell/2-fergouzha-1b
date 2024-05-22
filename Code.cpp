#include "Code.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

Code::Code(int n, int m) {
    // Initialize the secretCode vector with n random digits in the range
    // [0, m-1]

    //assigns n and m to private ints so initializeRandom() can access them
    nVal = n;
    mVal = m;
    initializeRandom();
}

Code::Code(int n, int m, vector<int> preexistingValues) : nVal(n), mVal(m), secretCode(preexistingValues) {
    // Initialize the secretCode vector with n preexisting digits in the range
    // [0, m-1]
}

void Code::initializeRandom() {
    // Initialize the secretCode vector with n random digits in the range
    // [0, m-1]

    //populates secretCode with n random digits
    for (int i = 0; i < nVal; i++)
        //adds a new random digit to secretCode based on the range [0, m-1]
        secretCode.push_back(rand() % mVal);
}

//TODO: This entire function may be redundant, or at least could be changed to
// be more compatible with Mastermind:printSecretCode()
void Code::printSecretCode() const {
    //prints the values of secretCode via cout

    //steps through each value of secretCode and prints it
    for (int i = 0; i < nVal; i++) {
        cout << secretCode.at(i);
        //checks to make sure a comma is not printed after the last digit
        if (i < (nVal - 1))
            cout << ", ";
    }
}

int Code::checkCorrect(const Code& guess) {
    // Compare the guess with the secretCode and return the number of correct
    // digits in the correct location

    //tracks number of correct digits
    int correctDigits = 0;
    //steps through every value of the secret code
    for (int i = 0; i < nVal; i++)
        //increments correctDigits if a guess digit matches the code digit
        if (guess.secretCode.at(i) == secretCode.at(i))
            correctDigits++;
    return correctDigits;
}

int Code::checkIncorrect(const Code& guess) {
    // Compare the guess with the secretCode and return the number of correct
    // digits in the incorrect location
    // No digit should be counted more than once

    //tracks number of misplaced digits
    int misplacedDigits = 0;
    //tracks whether a digit in the secret code was already checked
    bool recurringDigit;

    //"i" for loop: steps through every value of the secret code
    for (int i = 0; i < nVal; i++) {
        //resets recurringDigit to false before performing check
        recurringDigit = false;
        //"j" for loop: steps through every value of the secret code, again
        for (int j = 0; j < nVal; j++)
            //sets recurringDigit to true if the current secret code digit is
            //found elsewhere in the secret code
            if ((secretCode.at(j) == secretCode.at(i)) && (i > j)) {
                recurringDigit = true;
                //breaks "j" loop once a repeat digit is found
                break;
            }
        //skips checking the guess if the current digit is a repeat
        if (!recurringDigit)
            //"k" for loop: steps through guess to find misplaced digits
            for (int k = 0; k < nVal; k++)
                //checks for digits present in the code at a different place
                if ((guess.secretCode.at(k) == secretCode.at(i)) && (i != k)) {
                    //increments count of misplacedDigits
                    misplacedDigits++;
                    //breaks "k" loop to prevent recounts of the same digit
                    break;
                }
    }
    return misplacedDigits;
}

/*
int Code::check_incorrect(const vector<int>& guess) const {
    int count = 0;
    vector<int> secret_copy = secret_code;
    for (int i = 0; i < n; ++i) {
        auto it = find(secret_copy.begin(), secret_copy.end(), guess[i]);
        if (it != secret_copy.end()) {
            count++;
            secret_copy.erase(it);
        }
    }
    count -= check_correct(guess);
    return count;
}
*/