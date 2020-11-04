/**
 * @file obs.h
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит классы
 */
#ifndef obs
#define obs
#include <iostream>
#include <list>
#include <string>
class Subject;
class Road{
friend void movel(Road *r);
friend void bye(Road* r);
public:
  int stopx; int stopy; int stop;
  int cordX;
  int cordY;
  int direction;
  int drive;
  Road(){stop=0;}
  virtual int del()=0;
  std::string stat;
  virtual std::string status()=0;
  virtual void getplace()=0;
  virtual void info() = 0;
  virtual ~Road() {}
  void Update(const int &color_from_subject) {
  drive = color_from_subject;}
};
class Subject {
 public:
  int color=1;
  virtual ~Subject() {
 }
  /**
  * Методы управления подпиской.
  */
  void Attach(Road* observer)  {
  list_observer_.push_back(observer);
  }
  void Detach(Road* observer)  {
  list_observer_.remove(observer);
  }
  void Notify()  {
  std::list<Road *>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end()) {
  (*iterator)->Update(color);
  ++iterator;}
  }
  void Changecolor() {
  this->color = color*(-1);
  Notify();
  }
 private:
  std::list<Road *> list_observer_;};
#endif
