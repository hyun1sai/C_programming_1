#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double Standard_Deviation(double* ptr);
int main(void)
{
	double arr[5];
	int i;
	printf("Enter 5 real numbers: ");
	scanf("%lf %lf %lf %lf %lf", &arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);
	printf("Standard Deviation = ");
	printf("%.3f", Standard_Deviation(arr));
	return 0;
}
double Standard_Deviation(double *ptr)
{
	int i;
	double ave=0, result=0,xminusave;
	for (i = 0;i < 5; i++)
	{
		ave += ptr[i];
	}
	ave /= 5;
	for (i = 0;i < 5; i++)
	{
		xminusave = ptr[i] - ave;
		xminusave = xminusave * xminusave;
		result += xminusave;
	}
	result /= 5;
	result=sqrt(result);
	return result;
}