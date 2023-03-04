#pragma once
#include "repository.h"
#include "Observer.h"

class Service: public Subject{
private:
    Repository& repository;
public:
    Service(Repository& repository1);
    ~Service() = default;
    std::vector<Participant*> get_all_participants_service();
    std::vector<Question> get_all_questions_service();
    std::vector<Question> sort_questions_by_id();
    std::vector<Question> sort_questions_by_score();
    void add_question_service(const int id, const std::string &text, const std::string &correct, const int score);
};