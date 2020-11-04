/**
 * @file obs.h
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит фабрику
 */
#pragma once
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "ped.h"
#include "car.h"
class Factory{
public:
  virtual Road* Create() = 0;
  virtual ~Factory(){}
};
class PedestrianFactory:public Factory{
public:
  Road* Create(){
  return new Pedestrian;
 }
};
class CarFactory:public Factory{
public:
  Road* Create(){
  return new Car;}
};
/**
* Функция создания
* @param value объект
*/
Road* foo(Factory *value){
 return value->Create();
}
