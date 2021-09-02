#include "tcpserver.h"
#include "ui_tcpserver.h"


TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    setWindowTitle("server: 8888");
    server = new Server(this, 8888);
    ui->buttonStop->setEnabled(false);
    ui->buttonStart->setEnabled(true);
    connect(server, &Server::updateServer, this, &TcpServer::slotupdateServer);
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_buttonStart_clicked()
{
    ui->buttonStart->setEnabled(false);
    ui->buttonStop->setEnabled(true);
}

void TcpServer::on_buttonStop_clicked()
{

    ui->buttonStop->setEnabled(false);
    ui->buttonStart->setEnabled(true);
}

void TcpServer::slotupdateServer(QString msg, int length)
{
    //ui->textEditRead->append(msg);
}
