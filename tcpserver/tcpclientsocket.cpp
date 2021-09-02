#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent) : QTcpSocket(parent)
{
    //客户端发送过来的数据触发readyRead信号
    connect(this, &TcpClientSocket::readyRead, this, &TcpClientSocket::recvdata);
    connect(this, &TcpClientSocket::disconnected, this, &TcpClientSocket::slotclientdisconnected);
}

void TcpClientSocket::recvdata()
{
    QByteArray array = readAll();
    int length = array.size();
    QString msg = QString(array);
    emit updateServer(msg, length);
}


void TcpClientSocket::slotclientdisconnected()
{
    emit clientDisconnected(this->socketDescriptor());
}
