/**************************************************************************************************
 *
 *	Author:	Tom Rudolph	Date: 3/24/2017
 *	program to copy and concatenate strings
 *
 * ***********************************************************************************************/

#include<stdio.h>
#include<string.h>

//Function prototypes
void my_strncpy(char *dest, char *source, int n);
void my_strncat(char *dest, char *source, int n);

//main function
int main()
{
	char testSrc[] = "Hello";//string to get copied into other string
	char testDest[40] = "world";//where string gets put into
	int n =5;//size of source string
	
	my_strncat(testDest, testSrc, n);//calls concatenation function
	printf("CAT: %s \n", testDest);//prints out string after concatenation
	
	my_strncpy(testDest, testSrc, n);////calls copy function
	printf("CPY: %s \n", testDest);//prints out function after copy
	
	return 0;
}

void my_strncpy(char *dest, char *source, int n)//function to copy a string into another string
{
	int i;//declares int i
	for(i=0; i<n; i++)//runs from first to nth array element
	{
		dest[i] = source[i];//copies value into destination string
	}
	dest[i] = '\0';//adds null character to end of destination string
}

void my_strncat(char *dest, char *source, int n)//function to concatenate two strings
{
	int i=0, j=0;//intializes ints i and j to 0
	while(j<n)//while j is less than n
	{
		if(dest[i] == '\0')//if at the end of the destination string
		{
			dest[i] = source[j];//copies from source to the end of dest
			j++;//increments j
		}
		i++;//increments i
	}
	dest[i] = '\0';//adds null character to the end
}
