#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include<QFileDialog>
#include<QCoreApplication>
#include<QDebug>
#include<QShortcut>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QMediaPlayer *player;
  QVideoWidget *videoWidget;
  QMediaPlaylist *playlist;
  QStandardItemModel  *modelList;
  QHash <QUrl,qint64> hash;
  QShortcut *keyDel;
  int indexRow;

protected:

  bool event(QEvent *event) override;

private:

  void openPlaylist();

  void optionsTableView();

  void optionsVolume();

  void optionsVideoTime();

  void generalOptions();

  void generalOptions_2();

  void key();

  void nextPrevious();

  void writeBin();

  void readBin();

private slots:

  void playVideo();

  void pauseVideo(int);

  void typeToVolume(int);

  void getPosition();

  void findInHash();

  void startInTab();

  void indexToDelete();

  void message();

  void previous();

  void next();
};
#endif // MAINWINDOW_H
