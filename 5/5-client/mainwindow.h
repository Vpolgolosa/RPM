#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:

  QTcpSocket *sockCl;
  Ui::MainWindow *ui; 
  QString nick = " ";

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void execButtonAction();

  void readSocket();

  void setNick();

  void serverDisconnect();
};
#endif // MAINWINDOW_H
