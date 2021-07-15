/***************************************************************************************************
 *
 *	Author: Tom Rudolph	Date: March 20, 2017
 *	Section: 06
 *	Program to sort an array
 *
 **************************************************************************************************/

#include<stdio.h>
#define MAX_ARRAY_SIZE 50//defines the largest value array can be
//Method declarations
void populate_array(int[], int *);
void print_array( int[], int );
void swap( int[], int, int );
void quicksort( int[], int, int );
int partition( int[], int, int );

int main()
{
	int size;//int to keep track of number of elements in array
	int array[MAX_ARRAY_SIZE];//initializes array to have max number of indices
	populate_array(array, &size);//calls function to fill array
	printf("The initial array contains:\n");
	print_array( array, size );//prints unsorted array
	quicksort(array, 0, size-1);//sorts array
	printf("The array is now sorted:\n");
	print_array( array, size );//prints sorted array
}

void populate_array(int array[], int *n)//function to fill array with uset input
{
	int temp;
	printf("Enter the value of n: ");//Asks user for number of indices to use in array
	scanf("%i",&temp );//stores that in a temp variable
	if(temp > MAX_ARRAY_SIZE)//makes sure that the size given by the user is not great than max value
		temp=MAX_ARRAY_SIZE;
	*n = temp;//says the value at the pointer equals the temporary variable given by the user
	printf("Enter %i integers(positive, negative, or zero):\n", *n);
	for(int i=0; i<*n && i<MAX_ARRAY_SIZE; i++)//gets user input as long as the number of indices is less 
	{					   //than what the user said and that it is less than the maximum
						   //size
		scanf("%i", &array[i]);//stores value into index of the array
	}
}

void print_array( int array[], int n )//function to print all values in the array
{
	for(int i=0; i<n; i++)//prints out value as long as it is not at the final index
	{
		printf("%+5d\n", array[i]);//prints value at index with it printing at the fifth location 
	}
}

void swap(int array[], int i_1, int i_2)//Function to swap two values in an array
{
	int temp = array[i_1];//temp variable equals value at first given index
	array[i_1] = array[i_2];////value at first given index equals the value at second given index
	array[i_2] = temp;//value at second given index equals temp variable
}

void quicksort(int array[], int low, int high)//quicksort function
{
	if(low<high)//if the last index is greater than the first index
	{
		int pivot = partition(array, low, high);//finds pivot point
		quicksort(array, low, pivot-1);//quicksorts everythingbefore pivot
		quicksort(array, pivot, high);//quicksorts pivot and everything after
	}
}

int partition(int array[], int low, int high)//Partition function
{
	int pivot = array[high];//pivot equals last value in subarray
	int i = low-1;//i equals one less than the first index
	
	for(int j=low; j<high; j++)//while j is in between the high and low values
	{
		if(array[j] <= pivot)//if the value at j is less than or equal to the pivot
		{
			i++;//increment i
			swap(array, i, j);//swap val at i and j
		}
	}
	swap(array, i+1, high);//swap first and last values
	return i+1;//return one more than i
}
