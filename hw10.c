#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct
{
	char Name[50];
	char Country[50];
	int Population;
} City;
int main(void)
{
	City arr[3];
	int i;
	printf("Input three cities:\n");
	for (i = 0;i < 3;i++)
	{
		printf("Name> ");
		fgets(arr[i].Name, sizeof(arr[i].Name), stdin);
		arr[i].Name[strlen(arr[i].Name) - 1] = 0;
		printf("Country> ");
		fgets(arr[i].Country, sizeof(arr[i].Country), stdin);
		arr[i].Country[strlen(arr[i].Country) - 1] = 0;
		printf("Population> ");
		scanf("%d", &arr[i].Population);
		while (getchar() != '\n');
	}
	printf("Printing the three cities:\n");
	for (i = 0;i < 3;i++)
	{
		printf("%d. %s in %s with a population of %d people\n", i + 1, arr[i].Name, arr[i].Country, arr[i].Population);
	}
	return 0;
}