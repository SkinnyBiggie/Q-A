#pragma once
#include "vector"
#include "domain.h"

class Repository{
private:
    std::vector<Participant*> participants;
    std::string participantFile;
    std::vector<Question> questions;
    std::string questionFile;
public:
    Repository(std::vector<Participant*> participants, std::vector<Question> questions, std::string& participantFile, std::string& questionFile);
    std::vector<Participant*> get_all_participants_repo();
    std::vector<Question> get_all_questions_repo();
    std::string get_participants_file_repo();
    std::string get_questions_file_repo();
    void tokenizeParticipant(std::string read);
    void tokenizeQuestion(std::string read);
    void loadParticipantFromFile();
    void loadQuestionFromFile();
    void initRepo();
    int findByID(const int id);
    void addQuestionRepo(Question& question);
    void writeQuestionsToFile();
    void writeToFileRepo();
    void writeParticipantsToFile();
    ~Repository() = default;
};