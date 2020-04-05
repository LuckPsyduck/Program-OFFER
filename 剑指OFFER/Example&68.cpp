#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;
	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++, pEnd--;
	}
}

char* LeftRotateString(char *pStr, int n)
{
	if (pStr != nullptr)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char *pFirstStart = pStr;
			char *pFirstEnd = pStr + n - 1;
			char *pSecondStart = pStr + n;
			char *pSecondEnd = pStr + nLength - 1;

			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondStart, pSecondEnd);

			Reverse(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

// ====================²âÊÔ´úÂë====================
void Test(char* testName, char* input, int num, char* expectedResult)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	char* result = LeftRotateString(input, num);

	if ((input == NULL && expectedResult == NULL)
		|| (input != NULL && strcmp(result, expectedResult) == 0))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// ¹¦ÄÜ²âÊÔ
void Test1()
{
	char input[] = "abcdefg";
	char expected[] = "cdefgab";

	Test("Test1", input, 2, expected);
}

// ±ß½çÖµ²âÊÔ
void Test2()
{
	char input[] = "abcdefg";
	char expected[] = "bcdefga";

	Test("Test2", input, 1, expected);
}

// ±ß½çÖµ²âÊÔ
void Test3()
{
	char input[] = "abcdefg";
	char expected[] = "gabcdef";

	Test("Test3", input, 6, expected);
}

// Â³°ôÐÔ²âÊÔ
void Test4()
{
	Test("Test4", NULL, 6, NULL);
}

// Â³°ôÐÔ²âÊÔ
void Test5()
{
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test5", input, 0, expected);
}

// Â³°ôÐÔ²âÊÔ
void Test6()
{
	char input[] = "abcdefg";
	char expected[] = "abcdefg";

	Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

