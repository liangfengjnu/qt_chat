#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "account.h"


namespace Ui { class Login; }


class Login : public QWidget
{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);
    bool addAccount(QString userbane, QString password);
    bool login(QString userbane, QString password);
    ~Login();

private slots:
    void on_buttonSignUp_clicked();
    void on_buttonLogin_clicked();

private:
    Ui::Login *ui;
    Accounts *accounts;
   // ClientWidget w2;
signals:
    void signalLogin(QString);
};

#endif // LOGIN_H
