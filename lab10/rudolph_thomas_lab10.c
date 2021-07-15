/*************************************************************************
 *	
 *	Author: Tom Rudolph	Date: 4/8/2017
 *	Program using structures to classify elements	
 *	
 * **********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ELEMENTS 118//number of elements

#define ELEMENT_FILENAME "element_db.csv"

struct element_t{//declares sructure to keep track of characteristics of elemenets
	int atomic_num;//atomic number
	char name[15];//elements name
	char chem_symb[3];//symbol for elements(i.e. Fe for iron)
	char bonding_type[20];//class of elements
	char state[20];//state at room temperature
	float at_weight;//atomic weight of element
	char discovered[10];//When it was discovered
};

struct element_t elements[MAX_ELEMENTS];//initializes array of MAX_ELEMENTS indeces

void print_element( int i )//print out element values at index i
{
	printf("---------------\n");//prints top of chunk
	printf("| %d\t%.4f\n", elements[i].atomic_num, elements[i].at_weight);//prints atomic number and atomic weight
	printf("| %s\t%s\n", elements[i].chem_symb, elements[i].name);//prints out symbol and name
	printf("| %s\n", elements[i].state);	
	printf("| %s\n", elements[i].bonding_type);
	printf("| Found: %s", elements[i].discovered);	
	printf("---------------\n\n");//prints bottom of chunk
}

void fprint_element( int i, FILE * f )//prints element to file
{
	fprintf(f, "---------------\n");
	fprintf(f, "| %d\t%.4f\n", elements[i].atomic_num, elements[i].at_weight);
	fprintf(f, "| %s\t%s\n", elements[i].chem_symb, elements[i].name);
	fprintf(f, "| %s\n", elements[i].state);
	fprintf(f, "| %s\n", elements[i].bonding_type);
	fprintf(f, "| Found: %s", elements[i].discovered);
	fprintf(f, "---------------\n\n");
}

void find_elements( char c[], int b, FILE * f )//function to find element given in command line
{
	for(int i=0; i<MAX_ELEMENTS; i++)//goes through all elements to check chemical symbols
	{
		if(!strcmp(c, elements[i].chem_symb))//checks the chemical symbol of each element against the command line argument
		{
			switch(b){//determines which print function to call when correct chem symbol found
				case 0://if 0 passed for b, do not write to file but to command line output stream
					print_element(i);//call print function
					break;
				default: //if b is not zero, write to output file
					fprint_element(i,f);//call print function for output file
					break;
			}
		}
	}
}

int main(int argc, char *argv[])//main function with command line argument
{
	if(argc<2)//If no command line arguments, print warning and end main function
	{
		printf("ERROR: Please provide at least one program argument.\n");
		return 0;
	}
	
	FILE * element_file = fopen( ELEMENT_FILENAME, "r" );//open file and read it
	
	if(element_file != NULL )//if the file exists
	{
		char line[100];
		int i=0;
		while( fgets(line, 100, element_file ))//reads in line
		{
			int j=0;
			
			char * temp;//temporary char variable
			temp = strtok(line, ",");//reads temp up until delimiter(",")
			while(temp!=NULL)//while temp has characters
			{
				switch(j){
				case 0://if j=0, value is the atomic number
					elements[i].atomic_num = atoi(temp);
					break;
				case 1://if j=1, value is the chemical symbol
					strncpy(elements[i].chem_symb, temp, 3);
					break;
				case 2://if j=2, value is the name
					strncpy(elements[i].name, temp, 15);
					break;
				case 3://If j=3, value is the atomic weight
					elements[i].at_weight = atof(temp);
					break;
				case 4://if j=4, value is the element's state at room temperature
					strncpy(elements[i].state, temp, 20);
					break;
				case 5://if j=5, value is the elements bonding type
					strncpy(elements[i].bonding_type, temp, 20);
					break;
				case 6://If j=6, value is when the element was discovered
					strncpy(elements[i].discovered, temp, 10);
					break;
				}
				j++;//increment j	
				temp = strtok(NULL, ",");//read in next value from the line			
			}
			i++;//increment i to go to next element in array
		}
		fclose(element_file);//close file when finished
	}
	
	int bool = 0;//declares boolean variable to zero
	
	FILE * output_f = NULL;//declares pointer to output file to null
	
	for(int i=1; i<argc; i++)//goes through all the arguments in the command line
	{
		if(i == 1)//if at first input
		{
			char * dot = strchr( argv[i], '.');//have a pointer to a possible . indicating an output file
			if(dot)//if there is an output file
			{
				output_f = fopen( argv[i], "w");//open the file to write to				
				bool = 1;//have boolean variable be true
				continue;//continue with for loop, skipping rest of the lines
			}
		}
		find_elements(argv[i], bool, output_f);//calls find_elements function for each command line input
	}
	return 0;
}
