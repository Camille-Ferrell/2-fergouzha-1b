#include "Mastermind.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL)); // Random Time Seed

    int n, m;

    // Prompt the user to enter the code length and range of digits with error checking
    while (true) {
        cout << "Enter the code length (positive integer): ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
            cout << "Invalid input. Please enter a positive integer for the code length." << endl;
            continue;
        }
        break;
    }

    while (true) {
        cout << "Enter the range of digits (positive integer greater than 1): ";
        cin >> m;
        if (cin.fail() || m <= 1) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
            cout << "Invalid input. Please enter a positive integer greater than 1 for the range of digits." << endl;
            continue;
        }
        break;
    }

    Mastermind game(n, m);
    game.playGame();

    return 0;
}
