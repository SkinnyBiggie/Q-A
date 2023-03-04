#pragma once
#include "string"

class Question{
private:
    int id;
    std::string text;
    std::string correct;
    int score;
public:
    Question(): id{0}, text{""}, correct{""}, score{0} {}
    Question(const int id, const std::string& text, const std::string& correct, const int score);
    int getID() {return this->id;}
    std::string getText() {return this->text;}
    std::string getCorrect() {return this->correct;}
    int getScore() {return this->score;}
    std::string toStringParticipant();
    std::string toStringPresenter();
    ~Question() = default;
};

class Participant{
private:
    std::string name;
    int score;
public:
    Participant(): name{""}, score{0} {}
    Participant(const std::string& name, const int score);
    std::string getName() {return this->name;}
    int getScore() {return this->score;}
    std::string toString();
    ~Participant() = default;
};