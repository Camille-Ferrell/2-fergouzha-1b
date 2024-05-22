#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>

using namespace std;

class Response {
private:
    int numCorrect;
    int numIncorrect;

public:
    Response(int correct = 0, int incorrect = 0);   // Response constructor with default values of 0
    int getNumCorrect() const;                      // returns number of correct digits
    int getNumIncorrect() const;                    // returns number of misplaced digits
    void setNumCorrect(int c);                      // sets number of correct digits to arg c
    void setNumIncorrect(int i);                    // sets number of incorrect digits to arg i
    bool operator==(const Response& other) const;   // overloaded == operator 
    friend ostream& operator<<(ostream& os, const Response& response);
};

#endif // RESPONSE_H
