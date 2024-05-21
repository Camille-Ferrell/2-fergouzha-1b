#include "Mastermind.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL)); // Random Time Seed

    int n, m;
    cout << "Enter the code length: ";
    cin >> n;
    cout << "Enter the range of digits: ";
    cin >> m;

    Mastermind game(n, m);
    game.playGame();

    return 0;
}
