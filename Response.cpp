#include "Response.h"

Response::Response(int correct, int incorrect) : numCorrect(correct), numIncorrect(incorrect) {
    // Initializes numCorrect and numIncorrect
}

int Response::getNumCorrect() const {
    return numCorrect;
}

int Response::getNumIncorrect() const {
    return numIncorrect;
}

void Response::setNumCorrect(int c) {
    numCorrect = c;
}

void Response::setNumIncorrect(int i) {
    numIncorrect = i;
}

bool Response::operator==(const Response& other) const {
    //  Compares numCorrect and numIncorrect between this Response and the other
        return ((getNumCorrect() == other.getNumCorrect()) &&
            (getNumIncorrect() == other.getNumIncorrect()));
}

ostream& operator<<(ostream& os, const Response& response) {
    // Prints the response in the format "Correct: X, Incorrect: Y"
    os << "Correct: " << response.getNumCorrect()
        << ", Incorrect: " << response.getNumIncorrect();
    return os;
}
