/*
 * Tom Rudolph
 * Lab 6, CSCI 112
 * 1/23/2017
 */

#include <stdio.h>

int main(void)
{
//Declare required variables
double celsius=0.0, fahrenheit=0.0;

//get temperature in celsius
printf("Enter a temperature in degrees Celsius: " );
scanf("%d", &celsius);

//convert to fahrenheit
fahrenheit = (celsius * 1.8) + 32.0;

//print out the temperature in fahrenheit
printf("That is %.2f Fahrenheit \n", fahrenheit);

//get temperature in fahrenheit
printf("Enter a temperature in degrees Fahrenheit: ");
scanf("%d", &fahrenheit);

//convert to celsius
celsius = (fahrenheit-32.0)*(5.0/9.0);

//print out temperature in celsius
printf("That is %.2f Celsius \n", celsius);

return(0);
}

