//Authors: Sebastian Grobelny Nicki Padar
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include "vector.h"
void run(Vector *cities);
int main()
{
  Vector cities;
  initialize(&cities);
  readCities(&cities);
  readAirports(&cities);
  cleanCities(&cities);
  run(&cities);
  deallocate(&cities);
  return 0;
}//main()
void run(Vector *cities)
{
  char input[79];
  const char *ptr1, *ptr2;
  int index1, index2;
  printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
  fgets(input, 79, stdin);
  ptr1 = strtok(input, " ");
  ptr2 = strtok(NULL, "\n");
    
    while( !(strcmp(ptr1, "XXX") == 0) && !(strcmp(ptr2, "XXX") == 0))
    {
     index1 = findAirport(ptr1, cities);
     index2 = findAirport(ptr2, cities);
     
     if ( (index1 != -1) && ( index2 != -1))
      {
       calcDistance(cities, index1, index2);
      }//if calcDistance()
     
     if ( (index1 == -1))
      {
       printf("%s is not a valid airport.\n", ptr1);
      }//if printf()
     
     if ( (index2 == -1))
      {
       printf("%s is not a valid airport.\n", ptr2);
      }//if printf()
     
     printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
     fgets(input, 79, stdin);
     ptr1 = strtok(input, " ");
     ptr2 = strtok(NULL, "\n");
    }	
}//run()
  

