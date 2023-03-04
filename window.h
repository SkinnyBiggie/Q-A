
#ifndef E913_913_HORNEA_DORIAN_ALEXANDRU_1_WINDOW_H
#define E913_913_HORNEA_DORIAN_ALEXANDRU_1_WINDOW_H

#include <QWidget>
#include "Service.h"
#include "Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget, public Observer{
Q_OBJECT

public:
    explicit Window(Service& service, Participant* participant, QWidget *parent = nullptr);

    ~Window() override;
    void populateList();
    void connectSignalsAndSlots();
    void addQuestion();
    //void answerQuestion();
    void update() override;

private:
    Ui::Window *ui;
    Service& service;
    Participant* participant;
};


#endif //E913_913_HORNEA_DORIAN_ALEXANDRU_1_WINDOW_H
