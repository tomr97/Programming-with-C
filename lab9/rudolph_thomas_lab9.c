/*************************************************************************
 *	
 *	Author: Tom Rudolph	Date: 4/8/2017
 *	Program using structures to classify elements	
 *	
 * **********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTS 20//Max number of elements in the array

struct element_t{//declares sructure to keep track of characteristics of elemenets
	int atomic_num;//atomic number
	char name[15];//elements name
	char chem_symb[3];//symbol for elements(i.e. Fe for iron)
	char class[20];//class of elements
	float at_weight;//atomic weight in amu's
	int num_elec[7];//number of electrons in 7 shells
};

struct element_t elements[MAX_ELEMENTS];//initializes array of MAX_ELEMENTS indeces

void scan_element( int i )//scan values for element at index i
{
	//scanns atomic number, name, symbol, class and weight
	scanf("%d%s%s%s%f",&elements[i].atomic_num, elements[i].name, elements[i].chem_symb, elements[i].class, &elements[i].at_weight);
	//scans in inner 4 electron shells
	scanf("%d%d%d%d", &elements[i].num_elec[0], &elements[i].num_elec[1], &elements[i].num_elec[2], &elements[i].num_elec[3]);
	//scan outer 3 shells
	scanf("%d%d%d", &elements[i].num_elec[4], &elements[i].num_elec[5], &elements[i].num_elec[6]);
}

void print_element( int i )//print out element values at index i
{
	printf("---------------\n");//prints top of chunk
	printf("| %d\t%.4f\n", elements[i].atomic_num, elements[i].at_weight);//prints atomic number and atomic weight
	printf("| %s\t%s\n", elements[i].chem_symb, elements[i].name);//prints out symbol and name
	printf("| ");	
	
	for(int j=0; j<7; j++)//prints out the electrons until all of the remaining shells have zero
	{
		int has_elec = 0;//variable to check if non zero values for electrons remaining
		for(int k=j; k<7; k++)//checks if remaining shells has nonzero values
		{
			if(elements[i].num_elec[k]!=0)//if value at k is not equal to zero
			{			      //increment has_elec
				has_elec++;
			}
		}
		if(has_elec>0)//if shalls with electrons remaining, print out the value
		{
			printf("%d ", elements[i].num_elec[j]);
		}
	}
	
	printf("\n---------------\n\n");//prints bottom of chunk
}

int find_largest(int n)//finds index of element  with largest atomic number
{		       //takes number of elements as input
	int l_in = 0;//says that largest index is initially first index
	for(int i=1; i<n; i++)//runs through the rest of the indeces to compare
	{
		if(elements[i].atomic_num > elements[l_in].atomic_num)//if at_num at i is greater than at the largest index then
		{						      //the largest index equals i
			l_in = i;
		}
	}
	return l_in;//returns largest index
}

int find_smallest(int n)//finds index of element with smallest atomic number
{			//takes number of elements as input
	int s_in=0;//says that the smallest index is initialyy the first element
	for(int i=1; i<n; i++)//runs through the indeces to compare
	{
		if(elements[i].atomic_num < elements[s_in].atomic_num)//if at_num at i is less than the smallest index then
		{						      //the smallest index equals i
			s_in = i;
		}
	}
	return s_in;//returns smallest index
}

int main(int argc, char *argv[])//main function with command line argument
{
	if(argc != 2)//if not exactly one argument
	{
		printf("ERROR: You must provide exactly one argument to this program.\n");
	}
	else
	{
		int num = (int)strtol(argv[1], NULL, 10);//uses argument to find number of elements	
		if(num <= 0 || num > 20)//if num is not in index: (0, 20], then gives warning
		{
			printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20");						
		}
		else
		{
		
			for(int i=0; i<num; i++)//scans in num number of elements
			{							
				scan_element(i);
			}
			
			printf("%d total elements.\n", num);//prints number of elements
			//finds element with smallest atomic number with find_smallest function in the index location
			printf("%s had the smallest atomic number.\n", elements[find_smallest(num)].name);
			//finds element with largest atomic number with find_largest function as index
			printf("%s had the largest atomic number.\n", elements[find_largest(num)].name);
			
			for(int i=0; i<num; i++)//prints all elements
			{
				print_element(i);
			}	
		}
	}
}
