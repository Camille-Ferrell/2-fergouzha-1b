#ifndef CODE_H
#define CODE_H

#include <vector>
#include <iostream>

using namespace std;

class Code {
private:
    vector<int> secretCode;
    int nVal, mVal;

public:
    Code(int n, int m);                                 //constructor for a new, random code
    Code(int n, int m, vector<int> preexistingValues);  //constructor for a preexisting/guess code
    void initializeRandom();
    void printSecretCode() const;
    int checkCorrect(const Code& guess);
    int checkIncorrect(const Code& guess);
};

#endif // CODE_H
