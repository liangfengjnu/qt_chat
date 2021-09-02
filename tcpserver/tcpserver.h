#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字
#include "server.h"

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

protected slots:
    void slotupdateServer(QString, int);


private:
    Ui::TcpServer *ui;
    Server *server;

};

#endif // SERVERWIDGET_H
