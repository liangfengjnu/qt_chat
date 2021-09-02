#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login), accounts(new Accounts)
{
    ui->setupUi(this);
    accounts->account_size = 0;
    //QMessageBox::information(NULL, "Title", "Content");
}

Login::~Login()
{
    delete ui;
    delete accounts;
}

void Login::on_buttonSignUp_clicked()
{

    //注册
    //获取账号密码
    QString username = ui->lineEditAccount->text();
    QString password = ui->lineEditPassword->text();

    //增加一个账号
    if(addAccount(username, password))
    {
        QMessageBox::information(NULL, "notification", "sign up successfully!");
    }

}

void Login::on_buttonLogin_clicked()
{

    //登录
    //获取账号密码
    QString username = ui->lineEditAccount->text();
    QString password = ui->lineEditPassword->text();
    if(login(username, password))
    {
        emit signalLogin(username);
      //  w2.show();
        this->hide();
    }
}

bool Login::addAccount(QString username, QString password)
{
    if(accounts->account_size == MAX)
    {
        QMessageBox::information(NULL, "notification", "sign up error! The number of account is full!");
        return false;
    }

    for(int i = 0; i <= accounts->account_size; ++i)
    {
        if(username == accounts->accountArray[i].username)
        {
            QMessageBox::information(NULL, "notification", "sign up error! Account is already exist!");
            return false;
        }
    }

    accounts->accountArray[accounts->account_size].username = username;
    accounts->accountArray[accounts->account_size].password = password;
    accounts->account_size++;
    return true;
}

bool Login::login(QString username, QString password)
{
    for(int i = 0; i <= accounts->account_size; ++i)
    {
        if(username == accounts->accountArray[i].username)
        {
             if(password == accounts->accountArray[i].password)
                 return true;
             else
             {
                 QMessageBox::information(NULL, "notification", "sign in error! The password is error!");
                 return false;
             }
        }
    }
    QMessageBox::information(NULL, "notification", "sign in error! Account is not exist!");
    return false;
}


