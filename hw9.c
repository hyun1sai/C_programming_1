#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char sen[50];
	int i;
	printf("Input>");
	fgets(sen, sizeof(sen), stdin);
	sen[strlen(sen) - 1] = 0;
	for (i = 0;i < strlen(sen);i++)
	{
		if ('a' <= sen[i] && sen[i] <= 'z')
		{
			sen[i] -= 32;
		}
		else if ('A' <= sen[i] && sen[i] <= 'Z')
		{
			sen[i] += 32;
		}
	}
	printf("Output>");
	printf("%s", sen);
	
	return 0;
}