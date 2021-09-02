#include "server.h"
#include <QHostAddress>
#include <QDebug>

Server::Server(QObject *parent, int port) : QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //只要有新连接就生成一个新的套接字
    TcpClientSocket *tcpclientsocket = new TcpClientSocket(this);
    tcpclientsocket->setSocketDescriptor(socketDescriptor);

    QString ip = tcpclientsocket->peerAddress().toString();
    qDebug(ip.toUtf8());

    //将新创建的套接字加入到客户端套接字列表中
    tcpclientsocketList.append(tcpclientsocket);

    //接收到tcpclientsocket发过来的更新界面的信号
    connect(tcpclientsocket, &TcpClientSocket::updateServer, this, &Server::slotupdateServer);
    connect(tcpclientsocket, &TcpClientSocket::clientDisconnected, this, &Server::slotclientDisconnected);
  //  emit newConnected();
    // emit QTcpServer::newConnection();
}

void Server::slotupdateServer(QString msg, int length)
{
    //将这个信号发送给界面
    emit updateServer(msg, length);


    //将收到的信号发送给每个客户端，从套接字列表中找到需要接收的套接字
    for(int i = 0; i < tcpclientsocketList.count(); ++i)
    {
        QTcpSocket *item = tcpclientsocketList.at(i);

        QString sendInfo = msg;
        item->write(sendInfo.toUtf8().data());
    }
}

void Server::slotclientDisconnected(int descriptor)
{
    for(int i = 0; i < tcpclientsocketList.count(); ++i)
    {
        QTcpSocket *item = tcpclientsocketList.at(i);
        //如果有客户端断开连接，将列表中的套接字删除
        if(item->socketDescriptor() == descriptor)
        {
            tcpclientsocketList.removeAt(i);
            return;
        }
    }
    return;
}
