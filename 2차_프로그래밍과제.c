#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int checkCondition(const char* str, int length);
void encode(const char* str, int length, const char* encodingTable, char* newStr);
void decode(const char* str, int length, const char* encodingTable, char* newStr);
int main(void)
{
	char str[30] = { 0, };
	int length, a;
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char newStr[30] = { 0, };
	printf("====================================================\n");
	printf("\n");
	printf("패스워드를 입력하세요 (숫자와 알파벳을 혼합하여 8-12자): ");
	scanf("%s", str);
	length = strlen(str);
	while (1)
	{
		if (checkCondition(str, length) == 0)
		{
			printf("숫자와 알파벳을 혼합해 주세요: ");
			scanf("%s", str);
			length = strlen(str);
		}
		if (checkCondition(str, length) == 2)
		{
			printf("범위 내의 문자 수로 다시 입력하세요: ");
			scanf("%s", str);
			length = strlen(str);
		}
		if (checkCondition(str, length) == 1)
		{
			encode(str, length, encodingTable, newStr);
			printf("입력하신 패스워드가 %s로 암호화 되었습니다.\n", newStr);
			decode(str, length, encodingTable, newStr);
			printf("이를 다시 복호화한 결과, 패스워드는 %s입니다.\n", newStr);
			printf("\n");
			printf("====================================================\n");
			return 0;
		}
	}
}
int checkCondition(const char* str, int length)
{
	int i;
	// 숫자나 문자가 있으면 각각 1로 바뀐다
	int checkalpabat = 0;
	int checknumber = 0;
	// 1 길이 확인
	if (length < 8 || length>12)
	{
		return 2;
	}
	// 2 혼합 확인
	for (i = 0;i < length;i++)
	{
		// 숫자 확인
		if (48 <= str[i] && str[i] <= 57)
			checknumber = 1;
		// 소문자 확인
		if (97 <= str[i] && str[i] <= 122)
			checkalpabat = 1;
		// 대문자 확인
		if (65 <= str[i] && str[i] <= 90)
			checkalpabat = 1;
	}
	// 결과 도출
	if (checkalpabat + checknumber == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void encode(const char* str, int length, const char* encodingTable, char* newStr)
{
	int i;
	for (i = 0;i < length;i++)
	{
		// 숫자 인코딩
		if (48 <= str[i] && str[i] <= 57)
			if (48 <= str[i] && str[i] <= 55)
				newStr[i] = str[i] + 2;
			else
				newStr[i] = str[i] - 8;
		// 소문자 인코딩
		else if (97 <= str[i] && str[i] <= 122)
			newStr[i] = encodingTable[str[i] - 97];
		// 대문자,특수문자 그대로 나두기
		else
			newStr[i] = str[i];
	}
}
void decode(const char* str, int length, const char* encodingTable, char* newStr)
{
	int i, j;
	for (i = 0;i < length;i++)
	{
		//숫자 디코딩
		if (48 <= newStr[i] && newStr[i] <= 57)
			if (50 <= newStr[i] && newStr[i] <= 57)
				newStr[i] = newStr[i] - 2;
			else
				newStr[i] = newStr[i] + 8;
		// 소문자 디코딩
		else if (97 <= newStr[i] && newStr[i] <= 122)
			for (j = 0;j < 26;j++)
			{
				// 교수님에게 물어보기 완전 이상함
				if (newStr[i] == encodingTable[j])
				{
					newStr[i] = j + 97;
					break;
				}

			}
		// 대문자,특수문자 그대로 나두기
		else
			newStr[i] = newStr[i];
	}
}