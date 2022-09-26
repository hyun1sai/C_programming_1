#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double kilometer;
	double mile;
	printf("Please enter kilometers: ");
	scanf(" %lf", &kilometer);
    mile=kilometer/1.609;
	printf("%.1f km is equal to %.1f miles.", kilometer, mile);
	return 0;
}