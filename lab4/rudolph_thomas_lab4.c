/**************************************************************************************************
 *
 *	Author: Tom Rudolph		Date: 2/17/2017
 *	
 *	Lab4 Program to show sine, cosine and tangent for different angles
 *
 *************************************************************************************************/


#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define PI  3.14159	//Declares value of PI
#define LOOP_LIMIT  90	//Declares upper limit on angles

typedef enum {Sine, Cosine, Tangent, Quit} menu_t;//Declare enum with three trig functions and quit value

void print_sin()//Function to print sine values
{
	double rad;//temporary variable to hold radian value
	for(int i=0; i<= LOOP_LIMIT; i+=15)//Has for loop with increments of 15 for angle of degrees
	{
		rad = (double)i / 180.0 * PI;//finds the radian value for a certain angle in degrees
		printf("\tsin(%i) = %.4f\n", i, sin(rad));//prints out sine value
	}
	printf("\n");
}
void print_cos()//function to print out cosine function
{
	double rad;//temporary varible to hold radian value
	for(int i = 0; i<=LOOP_LIMIT; i+=15)//has 15 degree increments up to 90 degrees for printing different values of cosine of theta
	{
		rad = (double)i / 180.0 * PI;//Converts degrees to radians
		printf("\tcos(%i) =  %.4f\n", i, cos(rad));//prints out values of the cosine of theta		
	}
	printf("\n");
}

void print_tan()//function to print out values for tangent
{
	double rad;//variable to hold the value of the angle in radians
	for(int i = 0; i<LOOP_LIMIT; i+=15)//loop to print out the tangent of theta where theta is increasing in increments of 90 degrees
	{
		rad = (double)i / 180.0 * PI;//converts degrees to radians
		printf("\ttan(%i) = %.4f\n", i, tan(rad));//prints out values of tan(theta) until theta is 75
	}
	printf("\ttan(90) is UNDEFINED\n");//says that the tangent of 90 degrees is undefined
}

void pick()
{
	bool cont = true;//boolean variable for loop
	do{
		menu_t MENU;//variable for the enumerated data type
		printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) Quit\n");//asks for user input
		printf("Enter your choice > ");
		scanf("%u", &MENU);//gets user input and store into MENU

		switch(MENU){//switch statement to call the different trig function

			case 0://if MENU = 0, prints out values for sine
				print_sin();
				break;
			case 1://if MENU = 1, prints out values for cosine
				print_cos();
				break;
			case 2: //if MENU = 2, prints out value for tangent
				print_tan();
				break;
			case 3: //if MENU = 3, changes value of bool variable to say to not continue the loop
				cont = false;
				printf("You chose QUIT. Thank you, come again.\n\n");
				break;
			default: //Is called if input is invalid
				printf("%u is not a valid option. Please try again.\n\n", MENU);		

		}
		
	}while( cont );//while boolean variable has not been turned to false
}

int main()
{

	pick();	//calls function to pick which trig values to print out

}
