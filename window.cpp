
// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "ui_Window.h"
#include "QMessageBox"
#include "sstream"
#include "string.h"
#include "random"

Window::Window(Service& service, Participant* participant, QWidget *parent) :
         service(service), participant(participant), QWidget(parent), ui(new Ui::Window) {
    ui->setupUi(this);
    this->window()->setWindowTitle(QString::fromStdString(participant->getName()));
    this->populateList();
    this->service.addObserver(this);
    this->update();
    this->connectSignalsAndSlots();
}

Window::~Window() {
    delete ui;
}

void Window::update() {
    populateList();
}

void Window::populateList() {
    this->ui->questionListWidget->clear();
    if(this->participant->getName() == "Presenter"){
        for(auto& question: this->service.sort_questions_by_id()){
            this->ui->questionListWidget->addItem(QString::fromStdString(question.toStringPresenter()));
        }
    }
    else{
        for(auto& question: this->service.sort_questions_by_score()){
            this->ui->questionListWidget->addItem(QString::fromStdString(question.toStringParticipant()));
        }
    }
}

void Window::connectSignalsAndSlots() {
    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &Window::addQuestion);
    //QObject::connect(this->ui->AnswerButton, &QPushButton::clicked, this, &Window::answerQuestion);
}

void Window::addQuestion() {
    int id = this->ui->idLineEdit->text().toInt();
    std::string text = this->ui->textLineEdit->text().toStdString();
    std::string correct = this->ui->correctLineEdit->text().toStdString();
    try{
        if(text.empty() || correct.empty())
            throw "The text cannot be empty";
        else if(this->participant->getName() != "Presenter"){
            throw "Only the presenter can add questions";
        }
        else{
            int score = rand() % 10;
            this->service.add_question_service(id, text, correct, score);
            this->populateList();
        }
    }catch(const char *msg){
        auto *err = new QMessageBox();
        err->setIcon(QMessageBox::Warning);
        err->setText(msg);
        err->setWindowTitle("Invalid input");
        err->exec();
    }
}

/*void Window::answerQuestion() {
    std::stringstream current(ui->questionListWidget->currentItem()->text().toStdString());
    std::string answer = this->ui->participantLineEdit->text().toStdString();
    std::string text, correct, s_id;
    int id, score, total_score;
    getline(current, s_id, ' ');
    //getline(current, );
    if(participant->getName() != "Presenter"){
        if(question->getCorrect() == answer)
            participant->getScore() =  question->getScore();
    }
}*/