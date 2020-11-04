/**
 * @file alg.cpp
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит выполняемый алгоритм
 */
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "obs.h"
#define n 10
using namespace std;
/**
* Функция вывода на экран
* @param av существующие объекты
* @param ObjectRoad[n] объекты
* @param svetofor отслеживаемый объект
*/
void mapaful( int av[n], Road* ObjectRoad[n], Subject* svetofor ) {
 int x,y,m,p;
 for (int j=1; j<40; j++){
 y=j;
  for (int i=1; i<80; i++)
 { x=i; m=0; p=0;
 if ((x==15)&&(y==10))
 {
  if (svetofor->color==1) {cout<<"GOR";}
  else {cout<<"VER";}
  i=i+3; x=i;
 }
  for (int num=0; num<n; num++)
  {
  if (av[num]==1){
  if ((ObjectRoad[num]->cordX==x)&&(ObjectRoad[num]->cordY==y)&&(ObjectRoad[num]->status()=="car"))
  {m=1;}
  else if ((ObjectRoad[num]->cordX==x)&&(ObjectRoad[num]->cordY==y)&&(ObjectRoad[num]->status()=="pedestrian"))
  {p=1;}}}
  if (m==1) {cout<<"#";} else if (p==1){cout<<"$";}
  else{
  if (((x==35)||(x==45))&&((y<=14)||(y>=26)))
  {cout<<"|";}
  else if (((y==15)||(y==25))&&((x<=35)||(x>=46)))
  {cout<<"_";}
  else cout<<" "; }
  }
  cout<<endl;}
}
/**
* Функция передвижения объектов
* @param r объект
*/
void movel(Road* r) {
                 if(((r->direction==1)&&(r->drive==-1))||((r->direction==1)&&(r->stop==1)))r->cordY=r->cordY+1;
               else if(((r->direction==2)&&(r->drive==-1))||((r->direction==2)&&(r->stop==1)))r->cordY=r->cordY-1;
               else if(((r->direction==3)&&(r->drive==1))||((r->direction==3)&&(r->stop==1)))r->cordX=r->cordX+1;
               else if(((r->direction==4)&&(r->drive==1))||((r->direction==4)&&(r->stop==1)))r->cordX=r->cordX-1;
}
/**
* Функция проверки необходимости слежения за светофором
* @param r объект
*/
void bye(Road* r)
{
    if (((r->cordX==r->stopx+3)&&(r->direction==3))||((r->cordY==r->stopy+3)&&(r->direction==1))||((r->cordY==r->stopy-3)&&(r->direction==2))||((r->cordX==r->stopx-3)&&(r->direction==4)))
        r->stop=1;
}
