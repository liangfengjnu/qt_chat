#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <iostream>
#include <string>
using namespace std;

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = nullptr);

protected slots:
    void recvdata(); //处理readyRead信号读取数据
    void slotclientdisconnected(); //客户端断开触发disconnected,处理这个信号

signals:
    void updateServer(QString, int); //用来告诉tcpserver需要更新界面
    void clientDisconnected(int); //高速server有客户端断开

public slots:

private:
    size_t strSize;

};

#endif // TCPCLIENTSOCKET_H
