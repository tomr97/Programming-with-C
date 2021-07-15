/*************************************************************************
 *
 *	Author: Tom Rudolph	Date: 3/2/2017
 *	Program for equations of motion
 *
 * **********************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>
//function declarations
void equation1(float *in);
void equation2(float *);
void equation3(float *);
void equation4(float *);

float get_position_initial();
float get_position_final();
float get_velocity_initial();
float get_velocity_final();
float get_acceleration();
float get_time();

int user_menu();

int main()
{
	float in, result;//declares floats for calculating the result
	int choice = 5;//initializes choice to 5

	do{
		choice = user_menu();//asks user for choice of function

		switch(choice){//switch statement for choices
		
			case 1://if user chose 1, equation 1 is called
				equation1(&in);
				break;
			case 2://if user chose 2, equation2 is called
				equation2(&in);
				break;
			case 3: //if user chosse 3, equation 3 is called
				equation3(&in);
				break;
			case 4://If user chose 4, equation 4 is called
				equation4(&in);
				break;
		}
				
		result = in;//sets result to equal in
		if(choice!=5)//if choice is 1-4, prints result
			printf("Your result is %.4f\n\n", result);
	
	}while(choice!=5);//continues as lon as choice is not 5

	printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");

	return 0;
}

float get_position_initial()//function to get initial position
{
	float x_i;
	printf("\tEnter initial position: ");
	scanf("%f", &x_i);
	return x_i;
}

float get_position_final()//function to get final position
{
	float x_f;
	printf("\tEnter final position: ");
	scanf("%f", &x_f);
	return x_f;
}

float get_velocity_initial()//function to get initial velocity
{
	float v_i;
	printf("\tEnter initial velocity: ");
	scanf("%f", &v_i);
	return v_i;
}

float get_velocity_final()//function to get final velocity
{
	float v_f;
	printf("\tEnter final velocity: ");
	scanf("%f", &v_f);
	return v_f;
}

float get_acceleration()//function to get acceleration
{
	float a;
	printf("\tEnter acceleration: ");
	scanf("%f", &a);
	return a;
}

float get_time()//function to get time
{
	float time;
	printf("\tEnter the time: ");
	scanf("%f", &time);
	return time;
}

int user_menu()//gets users choice on equation to run
{
	int eq=5;//initializes equation to 5
	do{
		if(eq>5 || eq<1)//if equation number is out of bounds, it says so
		{
			printf("Invalid option. Please try again.\n\n");
		}
		printf("Enter a motion equation 1-4 or choose 5 to QUIT: ");//asks for equation number
		scanf("%i", &eq);//scans equation number

	}while(eq>5 || eq<1);//repeats if equation number is out of bounds
	return eq;//returns equation number
}

void equation1( float *in )//equation 1
{	//asks for and stores parameters
	float vo = get_velocity_initial();
	float a = get_acceleration();
	float t = get_time();	
	*in = vo + a*t;//returns first equation	
}

void equation2( float *in )//equation 2
{	//gets parameters
	float xo = get_position_initial();
	float vo = get_velocity_initial();
	float t = get_time();
	float a = get_acceleration();
	*in = xo + vo*t + 0.5*a*t*t;//returns equation 2
}

void equation3( float *in )//equation 3
{	//gets paramters
	float vo = get_velocity_initial();
	float a = get_acceleration();
	float xf = get_position_final();
	float xo = get_position_initial();
	*in = sqrt( vo*vo + 2*a*(xf-xo) );//returns equation 3
}

void equation4( float *in )//equation 4
{	//gets parameters
	float xo = get_position_initial();
	float vf = get_velocity_final();
	float vo = get_velocity_initial();
	float t = get_time();
	*in = xo + 0.5*(vf + vo)*t;//returns equation 4
}
