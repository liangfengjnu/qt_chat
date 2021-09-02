#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include <QList>
#include "tcpclientsocket.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0, int port = 0);
    QList<TcpClientSocket*> tcpclientsocketList;

protected:
    virtual void incomingConnection(qintptr socketDescriptor);

protected slots:
    void slotupdateServer(QString, int);
    void slotclientDisconnected(int);

signals:
    void updateServer(QString, int);
    //void newConnected();
};

#endif // SERVER_H
