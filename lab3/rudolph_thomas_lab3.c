#include<stdio.h>
#include<math.h>
#include<float.h>

int get_n(void)	//Gets an integer value
{
	int temp;//Declares a temporary integer variable
	printf("Enter an integer value >= 0: ");
	scanf("%i", &temp);//Stores the user given input into the temporary variable
	return temp;//Returns the variable
}

double get_input(void)//Gets double input from user
{
	double temp;//Declares temporary double variable
	printf("\nEnter a value: ");
	scanf("%lf", &temp);//Stores user given input into temp
	return temp;//Returns temp
}

int main(void)
{
	int num_times, n=0;//num_times is variable to keep track of number of 
			   //values to use in calculations
			   //n increments if a value less than zero is given for
			   //num_times
	double lowest = DBL_MAX, highest = -DBL_MAX;//Keeps track of lowest and highest 
						    //	values
						    //Sets values that are guaranteed to
						    //	be replaced
	double sum=0.0, sum_sqrs=0.0;	//Declares variables for the sum and sum of squares
	double std_dev=0.0, average=0.0;//Declares variables for standard deviation
					//and average
	
	do{	//has do while loop to make sure a valid value is given for num_times
		if(n>0)//Checks if the do while loop has run before
		{
			printf("\nError! Invalid number.\n\n");//If do while loop has
							       //run before, prints an 
							       //error statement
		}
		num_times = get_n();//Gets integer value for num_times
		n++;//Increments n to say that the loop has run before
	
	}while(num_times < 0);//Leaves loop if num_times is out of bounds
			      //Repeats if num_times is out of bounds
	
	for(int i=0; i<num_times; i++)//Gets num_times number of inputs
	{
		double cur; //Declares temporary variable to keep track of inputs
		
		cur = get_input();//Gets input from user
		
		if (cur>highest)//If input is greater than highest, sets  highest to cur
		{
			highest = cur;
		}
		if (cur<lowest)//If input is less than lowest, sets lowest to cur
		{
			lowest = cur;
		}
		
		sum += cur;//Adds input to the sum
		sum_sqrs += pow(cur, 2);//Squares the input and then add it to sum of squares
	}

	if (num_times != 0)//If num_times is not zero, calculates average and standard
	{		   //deviation
		average = sum/num_times;
		std_dev = sqrt( (sum_sqrs/num_times) - pow(average, 2));
	}
	else//if num_times is zero, sets highest and lowest to zero
	{   //average and std_dev are declared to be 0, so they don't
	    //need to be set to anything
		highest = 0.0;
		lowest = 0.0;
	}
	
	//Prints out different values
	printf("\nThe Highest is: %.3f", highest);
	printf("\nThe Lowest is: %.3f", lowest);
	printf("\nThe Average is: %.3f", average);
	printf("\nThe Range is: %.3f", highest - lowest);
	printf("\nThe Standard deviation is: %.3f\n\n", std_dev);
	
	
	
	return(0);//Exits the program
}
