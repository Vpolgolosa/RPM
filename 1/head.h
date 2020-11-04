/**
 * @file head.h
 * @author Oreshnikov Egor <egorores@mail.ru>
 * @brief Содержит описание
 */
#ifndef head
#define head
#include <iostream>
#include <string>
#define n 10
class Subject;
class Road;
/**
* Функция вывода на экран
* @param av существующие объекты
* @param ObjectRoad[n] объекты
* @param svetofor отслеживаемый объект
*/
void mapaful( int av[n], Road* ObjectRoad[n], Subject* svetofor );
#endif
