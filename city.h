//Authors: Sebastian Grobelny Nicki Padar
#ifndef CITY_H
 #define CITY_H

typedef struct
{
 double longitude;
 double latitude;
 char *name;
 char *state;
 char airport[4];
 int population;
} City;

void initialize(City *cityarray);
void readCity( char *temp, City *cityarray);
void readAirport(char *temp, City *cityarray);
void copyTemp(City *temp, City *cityarray);
bool isEqual(const City *city_local, const City *cityarray);
void copyLocation(const City *city_local, City *cityarray);
void deallocate(City *city_local);
bool hasAirport(City *cityarray);
void setAirport(const char *temp, City *cityarray);
void calcDistance(const City *cityarray1, const City *cityarray2);
#endif
