#include "Response.h"

Response::Response(int correct, int incorrect) {
    this->correct = correct;
    this->incorrect = incorrect;
}

void Response::setCorrect(int c) {
    correct = c;
}

void Response::setIncorrect(int ic) {
    incorrect = ic;
}

int Response::getCorrect() const {
    return correct;
}

int Response::getIncorrect() const {
    return incorrect;
}

bool Response::operator==(const Response& other) const {
    return (correct == other.correct && incorrect == other.incorrect);
}

ostream& operator<<(ostream& os, const Response& response) {
    os << "Correct: " << response.correct << ", Incorrect: " << response.incorrect;
    return os;
}
