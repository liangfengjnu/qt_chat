#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QWidget>
#define MAX 100


struct Account
{
    QString username;
    QString password;
};

struct Accounts
{
    struct Account accountArray[MAX];
    int account_size;
};



#endif // ACCOUNT_H
