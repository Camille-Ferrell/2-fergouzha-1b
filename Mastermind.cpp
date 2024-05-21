#include "Mastermind.h"
#include <iostream>

using namespace std;

Mastermind::Mastermind(int n, int m) : secret_code(n, m) {
    secret_code.initialize_randomly();
}

Mastermind::Mastermind() : secret_code(5, 10) {
    secret_code.initialize_randomly();
}

void Mastermind::printSecretCode() const {
    secret_code.print_secret_code();
}

Code Mastermind::humanGuess() const {
    int n = secret_code.getLength();
    vector<int> guess(n);
    cout << "Enter your guess of length " << n << ": ";
    for (int i = 0; i < n; ++i) {
        cin >> guess[i];
    }
    return Code(guess);
}

Response Mastermind::getResponse(const Code& guess) const {
    int correct = secret_code.check_correct(guess.getSecretCode());
    int incorrect = secret_code.check_incorrect(guess.getSecretCode());
    return Response(correct, incorrect);
}

bool Mastermind::isSolved(const Response& response) const {
    return response.getCorrect() == secret_code.getLength();
}

void Mastermind::playGame() {
    printSecretCode();
    for (int attempt = 1; attempt <= 10; ++attempt) {
        cout << "Attempt " << attempt << endl;
        Code guess = humanGuess();
        Response response = getResponse(guess);
        cout << response << endl;
        if (isSolved(response)) {
            cout << "Congratulations! You guessed the code correctly!" << endl;
            return;
        }
    }
    cout << "Sorry, you did not guess the code within 10 attempts. The correct code was: ";
    printSecretCode();
}
