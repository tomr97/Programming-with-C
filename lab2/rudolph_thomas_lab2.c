#include <stdio.h>

double get_input(void) //Gets input from user
{
double val;	      		//Initializes temporary variable  to store value that the function returns
printf("Enter a value > ");	
scanf("%lf", &val);		//Gets input and stores it into val

return(val);	//Returns input from user
}

double get_next(double x_2, double x_1)	//Finds next value in sequence with x_2 being X n-2
{
double next = (x_2/2.0) + 3.0 * x_1;	//Calculates the next value
return next;	//Returns next value
}

void print_result(double result)
{
printf("The result is: %.2f\n", result);//Returns fifth value with 2 places after decimal showing
}

int main(void)
{
double values[5];	//Initializes array to hold all 5 values calculated 
int index = 0;		//Keeps track of index in the array to be filled in

do 	//Initializes do while loop to fill in values for the array
{

if(index<2) 	//Uses get_input() for first two indexes in values
{
values[index] = get_input();
}
else	//If not the first or second index, uses get_next() to calculate next value in array
{
values[index] = get_next(values[index-2], values[index-1]);
}
index++;	//Increments index
}while(index<5);//Ensures that only five values are in the values array


print_result( values[4]);	//Calls print result with last value of array passed as the parameter

return(0);
}
