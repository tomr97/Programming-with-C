/******************************************************************************************************************
 *
 *	Author: Tom Rudolph		Date: 2/25/2017
 *	Program to test authenticity of barcodes
 *
// ***************************************************************************************************************/

#include<stdio.h>	

int barcode[12];//Declares a barcode with 12 indices with a scope of the entire file

//****************************************************************************************************************
void get_code()//Method to get barcode from user
{
	printf("Enter a barcode to check. Seperate digits with a space >\n");
	scanf("%i%i%i%i%i%i", &barcode[0], &barcode[1], &barcode[2], &barcode[3], &barcode[4], &barcode[5]);//scans in first six indices of the barcode
	scanf("%i%i%i%i%i%i", &barcode[6], &barcode[7], &barcode[8], &barcode[9], &barcode[10], &barcode[11]);//scans in second six
}

//****************************************************************************************************************

int triple_odd()//function to return three times the sum of digits 1,3,5,7,9,11(Indices 0,2,4,6,8,10)
{
	int sum=0;//initializes a temporary sum variable
	for(int i = 0; i<=10; i+=2)//goes through the odd indices, even digits
	{
		sum+=barcode[i];//adds the value of the barcode to the sum
	}
	return sum*3;//returns sum times 3
}

//****************************************************************************************************************

int sum_evens()//function to find the sum of the evens
{
	int sum=0;//initializes a temporary
	for(int i=1; i<11; i+=2)//goes through the even digits(odd indices)
	{
		sum+=barcode[i];//adds the value of the digit to the sum
	}
	return sum;//returns the sum
}

//****************************************************************************************************************

int check(int even, int odd)//function to find the predicted check digit
{
	int sum=even+odd;//adds together the even sum and three times the sum of the odd
	int last_dig=sum%10;//stores the last digit of the sum in the line above
	
	if(last_dig==0)//checks if the last digit is zero
	{
		return 0;//if zero, returns zero
	}
	else//if not zero
	{
		return 10-last_dig;//returns 10 minus the last digit
	}
}

//****************************************************************************************************************

void is_valid(int calc, int actual)//checks if function is valid
{
	if(calc == actual)//if the predicted and actual check digits are the same, it tells the uer that
	{
		printf("STEP 5: Check digit and last digit match.\nBarcode is valid\n\n");
	}
	else//if not, it prints that the barcode is invalid
	{
		printf("STEP 5: Check digit and last digit do not match.\nBarcode is INVALID\n\n");
	}
}

//****************************************************************************************************************

int main()
{
	int sum_odds, even_sum, calc_last;//declares variables
	
	get_code();//gets values of barcode
	
	sum_odds = triple_odd();//sets sum_odds to the output of three times the sum of the odd digits
	even_sum = sum_evens();	//sets even_sum equal to the sum of the even digits
	calc_last=check(sum_odds, even_sum);//calculates the last digit of the array
	
	printf("\nYou entered the code: %i %i %i %i %i %i ", barcode[0], barcode[1], barcode[2], barcode[3], barcode[4], barcode[5]);//prints out the 
	printf("%i %i %i %i %i %i ", barcode[6], barcode[7], barcode[8], barcode[9], barcode[10], barcode[11]);		// digits of the barcode
	printf("\nSTEP 1: Sum of odds time 3 is %i", sum_odds); //Prints out three time the sum of the odd digits
	printf("\nSTEP 2: Sum of the even digits is %i", even_sum);//prints out the sum of the even digits
	printf("\nStep 3: Total sum is %i", (sum_odds+even_sum));//prints out the sum of the two prior sums
	printf("\nStep 4: Calculated check digit is %i\n", calc_last);//prints out calc check
	is_valid(calc_last, barcode[11]);//calls function to test validity of barcode
}
