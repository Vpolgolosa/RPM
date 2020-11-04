#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include<QDebug>

class BubbleSort : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
public:
  explicit BubbleSort(QObject *parent = nullptr,int *mass=nullptr,int val=0);

  bool running() const;

  void sortMass(int);

public slots:

  void run();

  void setRunning(bool running);

  void getMassiv();

private:
  int *massiv;
  int n;
  bool m_running;


signals:

  void nowMassiv(int*);

  void finished();

  void runningChanged(bool running);

};

#endif // BUBBLESORT_H
