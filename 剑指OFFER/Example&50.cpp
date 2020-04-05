#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int GetTranslationCount(const string& numbers)
{
	int length = numbers.length();
	int *counts = new int[length];
	int count = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		count = 0;
		if (i < length - 1)
			count = counts[i + 1];
		else
			count = 1;
		if (i < length - 1)
		{
			int digit1 = numbers[i] - '0';
			int digit2 = numbers[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
					count += counts[i + 2];
				else
					count += 1;
			}
		}
		counts[i] = count;
	}
	count = counts[0];
	delete[] counts;
	return count;
}

int GetTranslationCount1(int number)
{
	if (number < 0)
		return 0;
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);
}


// ====================²âÊÔ´úÂë====================
void Test(char* testName,int number, int expectedResult)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	if (expectedResult == GetTranslationCount1(number))
		printf("Expected result is: %d\n", expectedResult);

	printf("\n");
}

void Test1()
{
	int numbers = 12258;
	Test("Test1", numbers, 5);
}

void Test2()
{
	int numbers = 1;
	Test("Test2", numbers,1);
}

void Test3()
{
	int numbers = -12258;
	Test("Test3", numbers, 5);
}

void main()
{
	Test1();
	Test2();
	Test3();
}