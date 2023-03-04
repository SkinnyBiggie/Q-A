#include <QApplication>
#include <QPushButton>
#include "window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<Question> vectorQuestions;
    std::string questionFile = R"(D:\OOP assignments\e913-913-Hornea-Dorian-Alexandru-1\questions.txt)";
    std::vector<Participant*> vectorParticipants;
    std::string participantFile = R"(D:\OOP assignments\e913-913-Hornea-Dorian-Alexandru-1\participants.txt)";
    Repository repository{vectorParticipants, vectorQuestions, participantFile, questionFile};
    repository.initRepo();
    Service service{repository};
    std::vector<Window*> windows;
    for(auto participant:service.get_all_participants_service()){
        auto window = new Window(service, participant);
        windows.push_back(window);
    }
    for(auto window:windows){
        window->show();
    }
    a.exec();
    return 0;
}
