/* File: lab3_2.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 26.10.2014 */

#define _CRT_SECURE_NO_WARNINGS									// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>										
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846								// pi constant

double arctan_IE1(double x)
{
	int i = 0;													// cycle iterator
	double result = 0;											// arctan computation result
	double summant;												// sequence summant
	double threshold = 1e-9;									// precision threshold
	do
	{
		if(i%2)
			summant = -1 * pow(x, 2*i + 1)/(2*i + 1);
		else
			summant = pow(x, 2*i + 1)/(2*i + 1);
		result += summant;
		i++;
	}
	while(fabs(summant) >= threshold);
	return result;
}

double arccot_IE1(double x)
{
	return (M_PI/2 - arctan_IE1(x));
}

int main()
{
	double dvalue;												// arctan argument
	int i = 0;													// cycle iterator
	double result = 0;											// arctan computation result
	double summant;												// sequence summant
	double threshold = 1e-9;									// precision threshold

	printf("Enter arctan() argument: ");
	fflush(stdin);
	scanf("%lf", &dvalue);
	do
	{
		printf("Iteration %i\r", i);
		if(i%2)
			summant = -1 * pow(dvalue, 2*i + 1)/(2*i + 1);
		else
			summant = pow(dvalue, 2*i + 1)/(2*i + 1);
		result += summant;
		i++;
	}
	while(fabs(summant) >= threshold);
	printf("\narctan(%.3lf) computed with precision up to %.1le equals %lf rad\n", dvalue, threshold, result);
	printf("Function arctan_IE1 returned %lf rad\n", arctan_IE1(dvalue));
	printf("Function arccot_IE1 returned %lf rad\n", arccot_IE1(dvalue));

	system("pause");
	return 0;
}