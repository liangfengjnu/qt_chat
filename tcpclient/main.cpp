#include "clientwidget.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login login;
    ClientWidget client;
    login.show();

    QObject::connect(&login,&Login::signalLogin,&client , &ClientWidget::acceptedLogin);
    return a.exec();
}
