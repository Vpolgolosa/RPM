/**
 * @file ped.h
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит дочерний класс-пешеход
 */
#pragma once
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "obs.h"
using namespace std;
class Pedestrian:public Road{
public:
  string stat="pedestrian";
int del() override
{
  if ((cordX==47)||(cordX==33)||(cordY==13)||(cordY==27))
  return (-1);
  else return (0);
}
 string status() override
  {
  return stat;
 }
  virtual void getplace() override{
  int cor=1+rand()%8;
  if (cor==1) {cordX=34; cordY=14; direction=1;drive=-1; }
  if (cor==2) {cordX=34; cordY=14; direction=3;drive=1;}
  if (cor==3) {cordX=46; cordY=14; direction=1;drive=-1;}
  if (cor==4) {cordX=46; cordY=14; direction=4;drive=1;}
  if (cor==5) {cordX=34; cordY=26; direction=2;drive=-1;}
  if (cor==6) {cordX=34; cordY=26; direction=3;drive=1;}
  if (cor==7) {cordX=46; cordY=26; direction=4;drive=1;}
  if (cor==8) {cordX=46; cordY=26; direction=2;drive=-1;}
  stopx=cordX; stopy=cordY;
}
  void info(){
   cout << "Pedestrian appeared\n"<< " x="<<cordX<<" y="<<cordY<<" dir="<<direction<<endl; //<-- Информация на экран для наглядности
 }};
