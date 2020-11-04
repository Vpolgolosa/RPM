#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenu"
#include "QStyle"
#include <QWidget>
#include <QtWebSockets>
#include <QDebug>
#include <QMessageBox>




MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  if(Save == 0)
  {
  ui->onoff->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 50, 50);"));
  }
  ui->onoff->setText(" ");
  this->setWindowTitle("Server");
  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
  trayIcon->setToolTip("Server" "\n"
 "� абота со сворачиванием программы трей");
  QMenu * menu = new QMenu(this);
  QAction * viewWindow = new QAction(("� азвернуть окно"), this);
  QAction * quitAction = new QAction(("Выход"), this);
  connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
  connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
  connect(this, SIGNAL(onoff_clicked()),this,SLOT(on_onoff_clicked()));
  menu->addAction(viewWindow);
  menu->addAction(quitAction);
  trayIcon->setContextMenu(menu);
  trayIcon->show();
  connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
  this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
  connect(this, SIGNAL(callapse()),this,SLOT(on_callapse_clicked()));

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
  if(this->isVisible() && CE == 1){
  event->ignore();
  this->hide();
  QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

  trayIcon->showMessage("Tray Program",
  ("Приложение свернуто в трей. Для того чтобы, "
 "развернуть окно приложения, щелкните по иконке приложения в трее"),
  icon,
  2000);
  exit();
  }
}
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
  switch (reason){
  case QSystemTrayIcon::Trigger:
  if(CE == 1){
  if(!this->isVisible()){
  this->show();
  CE=0;
  } else {
  this->hide();
  }
  }
  break;
  default:
  break;
  }
}

void MainWindow::exit()
{
  close();
}
void MainWindow::on_callapse_clicked()
{
  CE = 1;
  exit();

}
void MainWindow::lurk_elements()
{
  ui->host->hide();
  ui->port->hide();
  ui->SaveSetting->hide();
  ui->host_label->hide();
  ui->port_label->hide();
}

void MainWindow::show_elements()
{

  ui->host->show();
  ui->port->show();
  ui->SaveSetting->show();
  ui->host_label->show();
  ui->port_label->show();
}

void MainWindow::server_start(){
  if (Save == 1){
 server = new Server();
 connect(server, &Server::info,this, &MainWindow::get_info);
  this->show_elements();
  ui->host->setText(server->getHost());
  ui->port->setText(server->getPort());
  } else {
  delete server;
  this->lurk_elements();
  }
}

void MainWindow::get_info(QString info){
  ui->textEdit->append(info);
}

void MainWindow::set_settings()
{
  QString host;
  quint16 port;
  if(ui->host->displayText() == "") {
  host = "127.0.0.1";
  } else {host = ui->host->displayText();}

  if(ui->port->displayText() == "") {
  port = 1113;
  } else {port = ui->port->displayText().toUInt();}

  server->set_settings(host, port);
}

void MainWindow::on_onoff_clicked()
{
  if (Save == 0){
  ui->onoff->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 250, 0);"));
  Save = 1;
  }
  else{
 Save = 0;
 ui->onoff->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 50, 50);"));
  }
  server_start();
}
void MainWindow::on_SaveSetting_clicked()
{
QString host;
quint16 port;
if(ui->host->displayText() == "") {
host = "127.0.0.1";
} else {host = ui->host->displayText();}

if(ui->port->displayText() == "") {
port = 1113;
} else {port = ui->port->displayText().toUInt();}

server->set_settings(host, port);
}
