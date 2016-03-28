//Authors: Sebastian Grobelny Nicki Padar
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "vector.h"

void initialize( Vector *cities)
 {
  cities -> size = 10;
  cities -> cityArray = (City*)malloc(cities -> size * sizeof(City));
  cities -> count = 0;

   for ( int i = 0; i < cities -> size; i++)
    {
    initialize(&cities -> cityArray[i]);
    }//for each cityArray
 }//initalize()

void readCities(Vector *cities)
 {
  FILE *fp = fopen("citypopulations.csv", "r");
  char temp[100];
 
  while((fgets(temp, 100, fp)!= NULL))
   {
          
    if ( (cities->count == cities -> size))
     {
      resize(cities);
     }//if resize()

    readCity( temp, &cities -> cityArray[cities->count]);  
    cities -> count = (cities->count) + 1;
   }//while fgets()
	
  fclose(fp);
 }//readCities()

void deallocate(Vector *cities)
 {

  for (int i = 0; i < cities->count; i++)
   {
   deallocate(&cities->cityArray[i]);
   }//for deallocate()
  
  free(cities->cityArray);
 }//deallocate()

void resize(Vector *cities)
 {
  City *temp_city;
  int copy, count;
  cities -> size = (cities -> size)*2;
  temp_city = (City*)malloc((cities -> size)*sizeof(City));
  
  for (copy = 0; copy < (cities -> size); copy++)
   {
   initialize(&temp_city[copy]);
   }//for initalize()

  for ( count = 0; count  < (cities -> size) / 2; count++)
   {    
   copyTemp(&temp_city[count], &cities->cityArray[count]);
   deallocate(&cities->cityArray[count]);
   }//for copyTemp() deallocate()
	
   free(cities -> cityArray);
   cities -> cityArray = (City*)malloc( cities -> size *sizeof(City));
   cities-> cityArray = temp_city;
 }//resize()

void readAirports(Vector *cities)
 {  
   FILE *fp = fopen("airportLL.txt", "r");
   char temp[100];
   int b = 0;
   City *city_local;	
   
   while(fgets(temp, 100, fp) != NULL)
    {
     
     if (temp[0] == '[')
      {
       city_local = (City *)malloc( 10 *sizeof(City));
       initialize(city_local);
       readAirport(temp, city_local);
	  
       for (int i = 0; i < (cities->count); i++)
        {
            b = isEqual(city_local, &cities->cityArray[i]);
	      
            if ( b == 1)
             {		       
              copyLocation(city_local, &cities->cityArray[i]);
             }//if copyLocation()
         }//for isEqual()
        }//if initialize() readAirport()
      }	
   fclose(fp);
   deallocate(city_local);
 }//readAirports()

void cleanCities( Vector *cities)
 {
  int i, b;

  for (i = 0; i < (cities->count); i++)
   {
    b = hasAirport(&cities->cityArray[i]);
    
    if (b == 0)
    {
     deallocate(&cities->cityArray[i]); 
     cities->cityArray[i] = cities->cityArray[(cities->count)-1];
     (cities->count) = (cities->count)-1;
     i = i-1;
     }//if deallocate()
   }//for hasAirport()  
 }//cleanCities()

int findAirport(const char *arguments, const Vector *cities)
 {
  int i, b;
  City *new_local;
  new_local = (City*)malloc(1*sizeof(City));
  setAirport(arguments, new_local);
  
  for ( i = 0; i < (cities->count) ; i++)
   {
    b = isEqual(new_local, &cities->cityArray[i]); 
    
    if (b == 1)
     {
      printf("Found%s",new_local->airport);
      return i;
     }//if
   
    }//for isEqual
  printf("BADFound%s",new_local->airport);
  return -1;	
}//findAirport

void calcDistance(const Vector *cities, const int index1, const int index2)
 {
  calcDistance(&cities-> cityArray[index1], &cities->cityArray[index2] );
 }//calcDistance
