#include "domain.h"

Question::Question(const int id, const std::string &text, const std::string &correct, const int score) {
    this->id = id;
    this->text = text;
    this->correct = correct;
    this->score = score;
}

Participant::Participant(const std::string &name, const int score) {
    this->name = name;
    this->score = score;
}

std::string Question::toStringParticipant() {
    return std::to_string(this->id) + " " + this->text + " " + std::to_string(this->score);
}

std::string Question::toStringPresenter() {
    return std::to_string(this->id) + " " + this->text + " " + this->correct + " " + std::to_string(this->score);
}

std::string Participant::toString() {
    return this->name + " " + std::to_string(this->score);
}