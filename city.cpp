//Authors: Sebastian Grobelny Nicki Padar
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "city.h"
#include "vector.h"
void initialize(City *cityarray)
{
  cityarray -> longitude = 0;
  cityarray -> latitude = 0;
  cityarray -> name = NULL;
  cityarray -> state = NULL;
  cityarray -> airport[0] = '\0' ;
  cityarray -> population = 0;
}//initalize()
void readCity( char *temp, City *cityarray)
{
  char  *ptr1, *ptr2, *ptr3;
  int pop;

  ptr1 = strtok(temp, ",");
  cityarray->name = (char*)malloc( (strlen(ptr1) + 1) *sizeof(char));
  strcpy(cityarray -> name, ptr1);
  ptr2 = strtok(NULL, ",");
  cityarray->state = (char*)malloc( (strlen(ptr2) + 1) *sizeof(char));
  strcpy(cityarray -> state, ptr2);
  ptr3 = strtok(NULL, "\n");
  pop = atoi(ptr3);
  cityarray->population = pop;
	
}//readCity()
void copyTemp( City *temp, City *cityarray)
 {
  temp->name = (char*)malloc(strlen(cityarray->name) + 1*sizeof(char));
  strcpy(temp->name, cityarray->name);
  temp->state = (char*)malloc(strlen(cityarray->state) + 1*sizeof(char));
  strcpy(temp->state, cityarray->state);
  temp->population = cityarray->population;

 }//copyTemp
bool isEqual(const City *city_local, const City *cityarray)
 {	
  int c, b;
  c = strcmp(city_local->name, cityarray->name);
  b = strcmp(city_local->airport, cityarray->airport);

  if ((c == 0) || (b == 0))
   {
    return 1;
   }//if
  else //not the same
   {
    return 0;
   }//else
 }//isEqual()
 
void copyLocation(const City *city_local, City *cityarray)
 {
  strcpy(cityarray->airport, city_local->airport);
  cityarray->latitude = city_local->latitude;
  cityarray->longitude = city_local->longitude;
 }//copyLocation()

void readAirport(char *newline, City *city_local)
 {	
  char *ptr1, *ptr2, *ptr3, *ptr4;
  double lat, lon;
  
  ptr1 = strtok(newline, " ");
  strncpy(city_local->airport, ptr1 + 1, 3);
  ptr2 = strtok(NULL, " ");
  lat = atof(ptr2);
  city_local->latitude = lat;
  ptr3 = strtok(NULL, " ");
  lon = atof(ptr3);
  city_local->longitude = lon;
  ptr4 = strtok(NULL, ",");
  city_local->name = (char *)malloc(strlen(ptr4) + 1 *sizeof(char));
  strncpy(city_local->name, ptr4 + 1, strlen(ptr4));
 }//readAirport()

void deallocate(City *city_local)
 {
  free(city_local->name);
  free(city_local->state);
 }//deallocate()
bool hasAirport(City *cityarray)
 {        
  
  if (cityarray->airport[0] == '\0')
   {
    return 0;
   }//if
  else //not the same
   {
    return 1;
   }//else
 }//hasAirport() 

void setAirport( const char *arguments, City *city_local)
 {
  city_local->name = (char*)malloc(20 * sizeof(char));
  strncpy(city_local->airport, arguments, 3);
 }//setAirport() 
void calcDistance( const City *cityarray1, const City *cityarray2)
 {
  double R = 3963, pop1, pop2, lat1, lon1, lat2, lon2, sines, cosines;
  int passengers, distance;
  pop1 = cityarray1->population;
  pop2 = cityarray2->population;
  lat1 = (M_PI / 180)*(cityarray1->latitude);
  lon1 = (M_PI / 180)*(cityarray1->longitude);
  lat2 = (M_PI / 180)*(cityarray2->latitude);
  lon2 = (M_PI / 180)*(cityarray2->longitude);
  passengers = (int)((pop1 * pop2) / (250000000));
  sines = sin(lat1)*sin(lat2); 
  cosines = cos(lat1)*cos(lat2)*cos(lon1-lon2); 
  distance = (int)(acos(sines + cosines)*R);
   
  if (distance < 100)
   {
   passengers = 0;
   }//if
 
  printf("%d passengers fly the %d miles from\n", passengers, distance);
  printf("%s,%s to ", cityarray1->name, cityarray1->state); 
  printf("%s,%s\n", cityarray2->name, cityarray2->state);
 }//calcDistance()
