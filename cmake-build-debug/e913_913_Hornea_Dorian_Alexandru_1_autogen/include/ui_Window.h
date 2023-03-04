/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QListWidget *questionListWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *idLineEdit;
    QLineEdit *textLineEdit;
    QLineEdit *correctLineEdit;
    QPushButton *addButton;
    QLabel *label_4;
    QPushButton *AnswerButton;
    QLineEdit *scoreLineEdit;
    QLabel *label_5;
    QLineEdit *participantLineEdit;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(1003, 475);
        questionListWidget = new QListWidget(Window);
        questionListWidget->setObjectName(QString::fromUtf8("questionListWidget"));
        questionListWidget->setGeometry(QRect(90, 50, 391, 331));
        label = new QLabel(Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 70, 49, 16));
        label_2 = new QLabel(Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 100, 49, 16));
        label_3 = new QLabel(Window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(570, 130, 81, 16));
        idLineEdit = new QLineEdit(Window);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setGeometry(QRect(650, 60, 113, 24));
        textLineEdit = new QLineEdit(Window);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));
        textLineEdit->setGeometry(QRect(650, 100, 181, 24));
        correctLineEdit = new QLineEdit(Window);
        correctLineEdit->setObjectName(QString::fromUtf8("correctLineEdit"));
        correctLineEdit->setGeometry(QRect(660, 130, 171, 24));
        addButton = new QPushButton(Window);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(670, 170, 80, 24));
        label_4 = new QLabel(Window);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(580, 350, 101, 16));
        AnswerButton = new QPushButton(Window);
        AnswerButton->setObjectName(QString::fromUtf8("AnswerButton"));
        AnswerButton->setGeometry(QRect(730, 420, 80, 24));
        scoreLineEdit = new QLineEdit(Window);
        scoreLineEdit->setObjectName(QString::fromUtf8("scoreLineEdit"));
        scoreLineEdit->setGeometry(QRect(190, 420, 113, 24));
        label_5 = new QLabel(Window);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(98, 420, 71, 20));
        participantLineEdit = new QLineEdit(Window);
        participantLineEdit->setObjectName(QString::fromUtf8("participantLineEdit"));
        participantLineEdit->setGeometry(QRect(690, 350, 241, 24));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        label->setText(QCoreApplication::translate("Window", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "Text", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "Correct answer", nullptr));
        addButton->setText(QCoreApplication::translate("Window", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "Enter your answer", nullptr));
        AnswerButton->setText(QCoreApplication::translate("Window", "Answer", nullptr));
        label_5->setText(QCoreApplication::translate("Window", "Current Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
