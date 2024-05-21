#include "Code.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

Code::Code(int n, int m) {
    this->n = n; // Getting Private Members
    this->m = m;
}

Code::Code(const vector<int>& guess) {
    this->secret_code = guess;
    this->n = guess.size();
    this->m = 0; // Not used in this context
}

void Code::initialize_randomly() {
    secret_code.clear();
    for (int i = 0; i < n; ++i) {
        secret_code.push_back(rand() % m);
    }
}

int Code::check_correct(const vector<int>& guess) const {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (guess[i] == secret_code[i]) {
            count++;
        }
    }
    return count;
}

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

void Code::print_secret_code() const {
    cout << "Secret Code: ";
    for (int digit : secret_code) {
        cout << digit << " ";
    }
    cout << endl;
}

int Code::getLength() const {
    return n;
}

const vector<int>& Code::getSecretCode() const {
    return secret_code;
}
