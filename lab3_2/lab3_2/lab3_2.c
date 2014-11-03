/* File: lab3_2.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 26.10.2014 */

#define _CRT_SECURE_NO_WARNINGS									// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>										
#include <stdlib.h>
#include <math.h>

double arctan_IE1(double);										// function prototypes
double arccot_IE1(double);
double errorAtan(double);
double errorCot(double);

int main()
{
	double dvalue;												// arctan argument
	int i = 0;													// cycle iterator
	double result = 0;											// arctan computation result
	double summant;												// sequence summant
	double threshold = 1e-9;									// precision threshold
	double pi = 4*atan(1.0);									// get the PI value


	printf("Enter arctan() argument: ");
	fflush(stdin);
	scanf("%lf", &dvalue);
	if(fabs(dvalue) >= 1)
	{
		printf("Sorry, this program only works for arguments of arctan with absolute value less than 1\n");
		system("pause");
		return 0;
	}

	do
	{
		printf("Iteration %i\r", i);							// just for convinience
		if(i%2)													// I used IF instead of computing powers of -1
			summant = -1 * pow(dvalue, 2*i + 1)/(2*i + 1);
		else
			summant = pow(dvalue, 2*i + 1)/(2*i + 1);
		result += summant;
		i++;
	}
	while(fabs(summant) >= threshold);							// continue the cycle as long as the last summant contribution is more than threshold
	system("mode CON: COLS=95");								// enlarge the console window so my beautiful table fits
	printf("\n |------------------------------------------------------------------------------------------|");
	printf("\n |  arctan_IE1  |  arccot_IE1  |     atan     |     acot     |   error atan  |  error acot  |");
	printf("\n |------------------------------------------------------------------------------------------|");
	printf("\n | %12.10lf | %12.10lf | %12.10lf | %12.10lf | %12.10lf | %12.10lf |", arctan_IE1(dvalue), arccot_IE1(dvalue), atan(dvalue), pi/2 - atan(dvalue), errorAtan(dvalue), errorCot(dvalue));
	printf("\n |__________________________________________________________________________________________|\n\n");
	printf("  ");

	system("pause");
	return 0;
}

double arctan_IE1(double x)
{
	int i = 0;													// cycle iterator
	double result = 0;											// arctan computation result
	double summant;												// sequence summant
	double threshold = 1e-9;									// precision threshold
	do
	{
		if(i%2)													// I used IF instead of computing powers of -1
			summant = -1 * pow(x, 2*i + 1)/(2*i + 1);
		else
			summant = pow(x, 2*i + 1)/(2*i + 1);
		result += summant;
		i++;
	}
	while(fabs(summant) >= threshold);							// continue the cycle as long as the last summant contribution is more than threshold
	return result;
}

double arccot_IE1(double x)										// since the mathematical functions are related, I make use of the previously written function
{
	double pi = 4*atan(1.0);
	return (pi/2 - arctan_IE1(x));
}

double errorAtan(double value)									// this function returns relative error compared to library arcus tangent function
{
	if(value)													// check for 0 input so we don't divide by 0
		return (arctan_IE1(value) - atan(value))/atan(value);
	else
		return 0;
}

double errorCot(double value)									// this function returns relative error compared to library arcus cotangent function
{
	double pi = 4*atan(1.0);
	if(value)
		return (arccot_IE1(value) - (pi/2 - atan(value)))/(pi/2 - atan(value));
	else
		return pi/2;
}
