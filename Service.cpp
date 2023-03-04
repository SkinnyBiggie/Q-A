#include "Service.h"
#include "algorithm"

bool sortFunctionID(Question question1, Question question2){
    if(question1.getID() < question2.getID())
        return true;
    else
        return false;
}

bool sortFunctionScore(Question question1, Question question2){
    if(question1.getScore() > question2.getScore())
        return true;
    else
        return false;
}

Service::Service(Repository &repository1):repository(repository1) {}

std::vector<Participant*> Service::get_all_participants_service() {
    return this->repository.get_all_participants_repo();
}

std::vector<Question> Service::get_all_questions_service() {
    return this->repository.get_all_questions_repo();
}

std::vector<Question> Service::sort_questions_by_id() {
    std::vector<Question> vector;
    vector = this->repository.get_all_questions_repo();
    std::sort(vector.begin(), vector.end(), sortFunctionID);
    return vector;
}

std::vector<Question> Service::sort_questions_by_score() {
    std::vector<Question> vector;
    vector = this->repository.get_all_questions_repo();
    std::sort(vector.begin(), vector.end(), sortFunctionScore);
    return vector;
}

void Service::add_question_service(const int id, const std::string &text, const std::string &correct, const int score) {
    Question question = Question(id, text, correct, score);
    this->repository.addQuestionRepo(question);
    notify();
}