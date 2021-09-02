#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket> //通信套接字
#include "login.h"


namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    QString username;

public slots:
    void acceptedLogin(QString);

private slots:
    void on_buttonConnect_clicked();

    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::ClientWidget *ui;

    QTcpSocket *tcpSocket; //通信套接字
};

#endif // CLIENTWIDGET_H
