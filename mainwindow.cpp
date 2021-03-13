#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->auth->setCurrentWidget(ui->Login_page);
    w2 = new MainWindow2();
    auth_enter_btn = ui->auth_enter_btn;
    auth_register_btn = ui->auth_register_btn;
    reg_back_auth_btn = ui->reg_back_auth_btn;
    reg_registration_btn = ui->reg_registration_btn;
    auth_back_btn = ui-> auth_back_btn;
    auth_restore_btn = ui-> auth_restore_btn;
    restore_btn = ui-> restore_btn;
    reg_input_Username = ui->reg_input_Username;
    reg_input_Email = ui->reg_input_Email;
    reg_input_password = ui->reg_input_password;
    auth_input_Email_Username = ui->auth_input_Email_Username;
    auth_input_password = ui->auth_input_password;
    reg_input_code = ui->reg_input_code;
    restore_input_Username_Email = ui->restore_input_Username_Email;
    restore_input_code = ui->restore_input_code;
    connect(auth_enter_btn, &QPushButton::clicked, this, &MainWindow::auth_enter_btn_click);
    connect(auth_register_btn, &QPushButton::clicked, this, &MainWindow::auth_register_btn_click);
    connect(reg_back_auth_btn, &QPushButton::clicked, this, &MainWindow::reg_back_auth_btn_click);
    connect(reg_registration_btn, &QPushButton::clicked, this, &MainWindow::reg_registration_btn_click);
    connect(auth_restore_btn, &QPushButton::clicked, this, &MainWindow::auth_restore_btn_click);
    connect(auth_back_btn, &QPushButton::clicked, this, &MainWindow::auth_back_btn_click);
    connect(restore_btn, &QPushButton::clicked, this, &MainWindow::restore_btn_click);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::auth_enter_btn_click()
{
    QString auser_email_name = auth_input_Email_Username->text();
    QString apass = auth_input_password->text();
    if(auser_email_name.length() == 0 || apass.length() == 0 ) {
        QMessageBox::warning(this, "Предупреждение", "Не все поля заполнены");
    }
    else if(auser_email_name.contains('@')==true)
    {
        QString auser_email = auser_email_name;
        if((apass!="12345"&&auser_email!="alina@yandex.ru"))
        {
            QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль");
        }
        else {
            w2->show();
            this->close();
        }
    }
    else
    {
        QString auser_name = auser_email_name;
        if((apass!="12345"&&auser_name!="alina"))
        {
            QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль");
        }
        else {
            w2->show();
            this->close();
        }
    }

}

void MainWindow::auth_register_btn_click()
{
    ui->auth->setCurrentWidget(ui->Sign_up_page);
}

void MainWindow::reg_back_auth_btn_click()
{
    ui->auth->setCurrentWidget(ui->Login_page);
}

void MainWindow::reg_registration_btn_click()
{
    QString rusername = reg_input_Username->text();
    QString remail = reg_input_Email->text();
    QString rpass = reg_input_password->text();
    QString rcode = reg_input_code->text();
    if(rusername.length() == 0 || remail.length() == 0 || rpass.length() == 0 ||  rcode.length() == 0) {
        QMessageBox::warning(this, "Предупреждение", "Не все поля заполнены");
    }
    else if(remail.contains('@')!=true) {
        QMessageBox::critical(this, "Ошибка", "Недействительный  адрес эл. почты");

    }
    else if(rpass!="12345"&&rusername!="alina")
    {
        QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль");
    }
    else {
        QMessageBox::information(this,"Успешно","Регестрация прошла успешно");
        w2->show();
        this->close();
    }
}

void MainWindow::auth_restore_btn_click()
{
    ui->auth->setCurrentWidget(ui->restore_page);
}

void MainWindow::auth_back_btn_click()
{
    ui->auth->setCurrentWidget(ui->Login_page);
}

void MainWindow::restore_btn_click()
{

    QString ruser_email_name = restore_input_Username_Email->text();

    QString rcode = restore_input_code->text();

    if(ruser_email_name.length() == 0 || rcode.length() == 0 ) {
        QMessageBox::warning(this, "Предупреждение", "Не все поля заполнены");
    }
    else if(ruser_email_name.contains('@')==true)
    {
        QString ruser_email = ruser_email_name;

        if((rcode!="0"&&ruser_email!="alina@yandex.ru"))
        {
            QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль");
        }
        else {
            QMessageBox::information(this,"Успешно","Восстановление прошло успешно");
            w2->show();
            this->close();
        }
    }
    else
    {
        QString ruser_name = ruser_email_name;
        if((rcode!="0"&&ruser_name!="alina"))
        {
            QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль");
        }
        else {
            QMessageBox::information(this,"Успешно","Восстановление прошло успешно");
            w2->show();
            this->close();
        }
    }

}
