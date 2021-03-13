#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainwindow2.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QAction>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    MainWindow2 *w2;
    QPushButton *auth_enter_btn;
    QPushButton *auth_register_btn;
    QPushButton *reg_back_auth_btn;
    QPushButton *reg_registration_btn;
    QLineEdit *reg_input_Username;
    QLineEdit *reg_input_Email;
    QLineEdit *reg_input_password;
    QLineEdit *reg_input_code;
    QLineEdit *auth_input_Email_Username;
    QLineEdit *auth_input_password;
    QLineEdit *restore_input_Username_Email;
    QLineEdit *restore_input_code;
    QPushButton *auth_back_btn;
    QPushButton *restore_btn;
    QPushButton *auth_restore_btn;

private slots:
    void auth_enter_btn_click();

    void auth_register_btn_click();

    void reg_back_auth_btn_click();

    void reg_registration_btn_click();

    void auth_restore_btn_click();

    void restore_btn_click();

    void auth_back_btn_click();

};
#endif // MAINWINDOW_H
