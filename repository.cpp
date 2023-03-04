#include "repository.h"
#include "fstream"
#include "sstream"
#include "algorithm"

Repository::Repository(std::vector<Participant *> participants, std::vector<Question> questions,
                       std::string &participantFile, std::string &questionFile) {
    this->participants = participants;
    this->questions = questions;
    this->participantFile = participantFile;
    this->questionFile = questionFile;
}

std::vector<Participant*> Repository::get_all_participants_repo() {
    return this->participants;
}

std::vector<Question> Repository::get_all_questions_repo() {
    return this->questions;
}

std::string Repository::get_participants_file_repo() {
    return this->participantFile;
}

std::string Repository::get_questions_file_repo() {
    return this->questionFile;
}

void Repository::tokenizeParticipant(std::string read) {
    std::string data[20];
    int index = 0;
    std::stringstream ss(read);
    std::string object;
    while(ss >> object){
        data[index] = object;
        index++;
    }
    Participant* participantToAdd = new Participant{data[0], std::stoi(data[1])};
    this->participants.push_back(participantToAdd);

}

void Repository::tokenizeQuestion(std::string read) {
    std::string data[20];
    int index = 0;
    std::stringstream ss(read);
    std::string object;
    while(ss >> object){
        data[index] = object;
        index++;
    }
    Question questionToAdd{std::stoi(data[0]), data[1], data[2], std::stoi(data[3])};
    this->questions.push_back(questionToAdd);
}

void Repository::loadParticipantFromFile() {
    if(!this->participantFile.empty()){
        Participant participantFromFile;
        std::ifstream fin(this->participantFile);
        std::string read;
        Participant readParticipant;
        while(std::getline(fin, read)){
            fin.clear();
            this->tokenizeParticipant(read);
        }
    }
}

void Repository::loadQuestionFromFile() {
    if(!this->questionFile.empty()){
        Question questionFromFile;
        std::ifstream fin(this->questionFile);
        std::string read;
        Question readQuestion;
        while(std::getline(fin, read)){
            fin.clear();
            this->tokenizeQuestion(read);
        }
    }
}

void Repository::initRepo() {
    this->loadParticipantFromFile();
    this->loadQuestionFromFile();
}

int Repository::findByID(const int id) {
    int search = -1;
    auto it = std::find_if(this->questions.begin(), this->questions.end(), [&id](Question& question) {return question.getID() == id;});
    if(it != this->questions.end())
        search = it - this->questions.begin();
    return search;
}

void Repository::addQuestionRepo(Question &question) {
    int search = this->findByID(question.getID());
    if(search != -1){
        throw "The question already exists";
    }
    this->questions.push_back(question);
    this->writeQuestionsToFile();
}

void Repository::writeQuestionsToFile() {
    if(!this->questionFile.empty()){
        std::ofstream fout(this->questionFile);
        for(auto question: this->questions){
            fout << question.toStringPresenter() << "\n";
        }
        fout.close();
    }
}

void Repository::writeParticipantsToFile() {
    if(!this->participantFile.empty()){
        std::ofstream fout(this->participantFile);
        for(auto participant: this->participants){
            fout << participant->toString() << "\n";
        }
        fout.close();
    }
}

void Repository::writeToFileRepo() {
    this->writeQuestionsToFile();
    this->writeParticipantsToFile();
}