//Authors: Sebastian Grobelny Nicki Padar
#ifndef VECTOR_H
 #define VECTOR_H
#include "city.h"
typedef struct 
{ City *cityArray;
  int size;
  int count;
} Vector;
void initialize(Vector *cities);
void readCities(Vector *cities);
void readAirports(Vector *cities);
void resize(Vector *cities);
void deallocate(Vector *cities);
void cleanCities(Vector *cities);
int findAirport(const char *temp, const Vector *cities);
void calcDistance(const Vector *cities, const int index1, const int index2);
#endif
