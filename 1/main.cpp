/**
 * @file main.cpp
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит меню программы
 */
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "fac.h"
#include "head.h"
#include <stdlib.h>
#include <time.h>
#define n 10
using namespace std;
int main()
{
Subject* svetofor = new Subject;
PedestrianFactory pedestrian;
CarFactory car;
int av[n]={0};
Factory *ptr1 = &pedestrian;
 Factory *ptr2 = &car;
Road *ObjectRoad[n]={0};
  int c,i,num,d;
  i=0; c=0; num=0;
while(!_kbhit())
  {
 if (c==4){
  svetofor->Changecolor();
  c=0;
  }
for (int i2=0; i2<n; i2++)
 {
  if (av[i2]==1)
  {
  if ((ObjectRoad[i2]->cordX==ObjectRoad[i2]->stopx)||(ObjectRoad[i2]->cordY==ObjectRoad[i2]->stopy))
             {svetofor->Attach(ObjectRoad[i2]); ObjectRoad[i2]->drive=svetofor->color;
  }
  bye(ObjectRoad[i2]);
  movel(ObjectRoad[i2]);
  d=ObjectRoad[i2]->del();
  if (d==-1) {delete ObjectRoad[i2]; av[i2]=0;}
  }
  }
   srand(time(NULL));
  int typ=0+rand()%2;
if (c==3){
  if (num>=n)
  { num=0;
  delete ObjectRoad[num];
  av[num]=0;}
  if (typ==0){
  ObjectRoad[num] = foo(ptr1); av[num]=1;
  }
  if (typ==1){
  ObjectRoad[num] = foo(ptr2); av[num]=1;
  }
  ObjectRoad[num]->getplace();
  num++;}
mapaful(av,ObjectRoad,svetofor);
 c=c+1;
  Sleep(1000);
  system("cls");
  i++;
  }
  return 0;}
