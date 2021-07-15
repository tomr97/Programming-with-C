/**************************************************************************************************
 *
 *	Author:	Tom Rudolph	Date:	3/29/2017 
 *	Program to reverse the words in a line
 *
 * ***********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 80

void reverse( char line[], int n )
{
	char temp[SIZE];//declares arrays
	char word[SIZE];
	int word_len = 0;//sets word length equal to zero

	for(int idx = n; idx>=0; idx--)//for loop to go backwards through array
	{
		if(line[idx]==' ' && word_len>0)//if there is a space and a wordlength, that word is copied
		{
			strncpy(word, &line[idx+1], word_len);//copies word 
			word[word_len] = ' ';//adds space
			word[word_len+1] = '\0';//adds null character
			strncat(temp, word, word_len+1);//copies word into temporary array

			word_len = 0;//resets wordlength to zero
		}
		else if( isalnum((int)line[idx]) )//if still part of word
		{	
			word_len++;//increments word length
		}
	}

	if( word_len > 0 )//if left over word
	{
		strncpy(word, line, word_len);//copies remaining word into word array
		strncat(temp, word, word_len);//copies word into temp array
	}
	strncpy(line, temp, n);//copies temp into the sent array
	
	line[n] = '\0';//adds null pointer
	
	memset(temp, '\0', n);//clears temp array
	
	printf("%s\n\n", line);//prints original array
}

int main(int argc, char *argv[])//Checks number of args and stores all the args into an array
{
	int num;//variable to keep track of the size of the array	
	char str[SIZE];//declares string

	if(argc < 2 || (num = (int)strtol(argv[1], NULL, 10))<0)//Checks number of args and
	{				//gets number value of the num the user inputed
		printf("ERROR: Please provide an integer greater than or equal to zero\n");
	}
	else if(argc>2)//If too many arguments
	{
		printf("Error: Too many arguments");
	}
	else//if conditions are correct, does the reverse function
	{
		for(int i=0; i<num ; i++)//does the following the number of times command line say
		{	
			if(fgets( str, SIZE, stdin ))//Gets line from user
			{
				reverse(str, (int)strlen(str));//calls reverse function
				memset(str, '\0', strlen(str));//clears array
			}
		}
	}
	return 0;//exits safely
}
