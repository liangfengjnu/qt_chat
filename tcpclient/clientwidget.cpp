#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
#include "account.h"
//#include "login.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = NULL;

    //分配空间，指定父对象
    tcpSocket = new QTcpSocket(this);

    setWindowTitle("client");


    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEditRead->setText("link to server successfully");
            }
            );

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                //获取对方发送的内容
                QByteArray array = tcpSocket->readAll();
                //追加到编辑区中
                ui->textEditRead->append(array);
            }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    //获取服务器ip和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //主动和服务器建立连接
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void ClientWidget::on_buttonSend_clicked()
{
    //获取编辑框内容
    QString str = ui->textEditWrite->toPlainText();

    //获取ip
    QString ip = tcpSocket->peerAddress().toString();

    //发送数据
    tcpSocket->write( username.toUtf8().data() );
    tcpSocket->write( ": ");
    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_buttonClose_clicked()
{
    //主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}

void ClientWidget::acceptedLogin(QString name)
{
   // ui->textEditRead->setText(username);
    username = name;
    ui->textUsername->setText(name);
    this->show();
}
