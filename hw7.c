#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr1[6] = { 1,2,3,4,5,6 };
	int arr2[6] = { 7,8,9,10,11,12 };
	int* parr1 = &arr1[0];
	int* parr2 = &arr2[0];
	int i;
	int temp=0;
	printf("arr1: ");
	for (i = 0;i < 6;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	printf("arr2: ");
	for (i = 0;i < 6;i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	printf("\n");
	printf("after swap");
	printf("\n");
	for (i = 0;i < 6;i++)
	{
		temp = *parr1;
		* parr1= *parr2;
		*parr2 = temp;
		parr1++;
		parr2++;
	}
	printf("arr1: ");
	for (i = 0;i < 6;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	printf("arr2: ");
	for (i = 0;i < 6;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}