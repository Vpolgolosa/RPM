#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include<QDebug>
#include<QRandomGenerator>
#include"bubblesort.h"

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  bool event(QEvent *event) override;

  void sortMassiv();

  QBarSet* getDiagram();

  void avgForValues(int,int,int);

  void createAxisX();

  void createAxisY();

  void createMassiv();
public slots:

  void beginSort();

  void endSort();

  void resultSort();

  void getMassiv(int* mass);

  void buttons();

  void stopTimer();
private:
  Ui::MainWindow *ui;
  QChart *chart;
  QChartView *chartView;
  int *massiv;
  int n=500000;
  QThread *thread;
  BubbleSort *bubble;
  QTimer *timer;
  QBarSeries *series;
  QBarSet *set;
  bool end=0;
};
#endif // MAINWINDOW_H

