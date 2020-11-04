#include "canvas.h"
#include "mainwindow.h"
#include <QMessageBox>

Canvas::Canvas(QObject *parent) : QGraphicsScene(parent){
  this->setSize("1");
  color = QColor(Qt::green);
}

Canvas::~Canvas(){}
void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event){
  addEllipse(event->scenePos().x()-(size/2),
 event->scenePos().y()-(size/2),
 size, size, QPen(Qt::NoBrush), QBrush(color));
  previousPoint = event->scenePos();
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
  addLine(previousPoint.x(), previousPoint.y(),
  event->scenePos().x(), event->scenePos().y(),
  QPen(color, size,Qt::SolidLine,Qt::RoundCap));
  previousPoint = event->scenePos();
}

void Canvas::setColor(QString color){
  this->color = color;
}

void Canvas::setSize(QString size){
  if(size.toInt()>0)
  this->size = size.toInt();
  else{
  QMessageBox::information(NULL,QObject::tr("Ошибка"), tr("� азмер не может равняться 0"));
  return; }
}
