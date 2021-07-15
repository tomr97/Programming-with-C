/*************************************************************************************************************************************
//
//	Author: Tom Rudolph	Date: 2/10/2017
//	CSCI 112-006
//	
//	Program to make a diamond of numbers based on user input
//	
//***********************************************************************************************************************************/

#include<stdio.h>
#include<stdbool.h>

//************************************************************************************************************************************

bool is_valid(int);//Declare is_valid function so it can be used by get_input

int get_input(void)
{
	int input;	//Creates local input variable
	bool valid;//variable to test validity of variable

	do//Creates loop to ensure that input is an odd number between 1 and 9
	{
		printf("Enter an odd integer value between 1 and 9 inclusive: ");//Asks user for input
		scanf("%i", &input);//Gets input and stores it into local input variable
		valid = is_valid(input);//tests validity of input
	}while(!valid);//Repeats if even, less than one or greater than nine

	return input;//Returns local input variable
}
//************************************************************************************************************************************
bool is_valid(int val)//Function to test if input is within range
{
	if(val > 9)//Tests if value is greater than upper bound
	{
		printf("\nYou have enter a number greater than 9. Please try again.\n\n");//Gives error message
		return false;//Returns false indicating out of bounds
	}
	else if(val < 1)//tests if value is within lower bounds
	{
		printf("\nYou have entered a number less than 1. Please try again.\n\n");
		return false;//Indicates out of bounds
	}

	if( ( val%2 ) == 0 )//tests if value is even
	{
		printf("\nYou have entered an even number. Please try again.\n\n");
		return false;//Returns false if even
	}
	
	return true;//If none of the tests indicate out of bounds or even, returns true
}
//***********************************************************************************************************************************
void print_pattern(int val)//Prints out pattern
{
	for(int i = 0; i < (val/2+1); i++)//for loop for top part of pattern
	{		
		printf("%*s", 2*( val/2 + 1 - i ) , " ");//Sends in the proper level of spaces based on row number
		for(int k = 0; k < 2*i+1; k++)//prints out proper number of numbers depending on the row
		{
			printf("%i ", (k+1));//prints the number
		}
		printf("\n");//Creates a new line
	}
	

	for(int j = 0; j < (val/2); j++)//for loop for bottom part of pattern
	{		
		printf("%*s", 2*(j+2) , " ");//Adds proper number of spaces per row
		for(int k = 1; k <= val-2*(j+1); k++)//for loop prints out the numbers a certain amount of times depending on the row
		{
			printf("%i ", k );//prints out the numbers
		}
		printf("\n");//moves to a new line
	}
	
}
//************************************************************************************************************************************
int main(void)//Main function
{
	int input;//Creates a variable to hold input
			
	input = get_input();//gets input from user and stores it into a variable
			
	print_pattern(input);//prints pattern based on input

	return(0);
}
