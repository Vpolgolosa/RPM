#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
  QSqlDatabase db;
  Ui::MainWindow *ui;
  QString field;
  QString tName1 = "0", tName2 = "0";

public:

  MainWindow(QWidget *parent = nullptr);

  ~MainWindow();
    void createTable(QString name);
    void setNameFields();
   void clearFields();
   void spinBox();

public slots:

  void connectDatabase();
    void showTable();
    void initQuery();
   void addStroke();
    void deleteStroke();
   void updateStroke();
    void change(QString n);
    void changeTable(QString name);};
#endif // MAINWINDOW_H
