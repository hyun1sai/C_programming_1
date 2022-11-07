#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr1[5],i;
	printf("Please input five integers: ");
	for (i = 0;i < 5;i++)
	{
		scanf(" %d", &arr1[i]);
	}
	printf("\n");
	printf("Odd numbers:");
	for (i = 0;i < 5;i++)
	{
		if (arr1[i] % 2 != 0)
		{
			printf(" %d", arr1[i]);
		}
	}
	printf("\n");
	printf("Even numbers:");
	for (i = 0;i < 5;i++)
	{
		if (arr1[i] % 2 == 0)
		{
			printf(" %d", arr1[i]);
		}
	}
	return 0;
}