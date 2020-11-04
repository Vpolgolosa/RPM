#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>

class Server : public QObject
{
  Q_OBJECT
private:
   QTcpServer* tcpS;

  QTcpSocket* client;

  QList <QTcpSocket*> clients;
  QFile file;
  QStringList list;
  int k = 0;

public:

  explicit Server(QObject *parent = nullptr); 

  ~Server();

private slots:

  void connectUser();

  void runClientAction();

  void disconnectUser();

  void send10Message();

signals:

  void serverClose();
};

#endif // SERVER_H
