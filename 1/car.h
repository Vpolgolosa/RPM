/**
 * @file car.h
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит дочерний класс-машину
 */
#ifndef binarySearch
#define binarySearch
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "obs.h"
class Car:public Road{
public:
string stat="car";
int del() override
{
  if ((cordX==0)||(cordX==80)||(cordY==0)||(cordY==40))
 return (-1);
}
 string status() override
 {
 return stat;
  }
 virtual void getplace() override{
  int cor=1+rand()%4;
  if (cor==1) {cordX=1; cordY=18; direction=3; drive=1;stopx=32;}
  if (cor==2) {cordX=79; cordY=22; direction=4; drive=1;int stopx=48;}
  if (cor==3) {cordX=38; cordY=1; direction=1;drive=-1;int stopy=12;}
  if (cor==4) {cordX=42; cordY=39; direction=2;drive=-1;stopy=28;}
  }
 void info(){
  cout<<stat << " appeared\n"<< " x="<<cordX<<" y="<<cordY<<" dir="<<direction<<endl;//<-- Информация на экран для наглядности
 }
};
#endif
