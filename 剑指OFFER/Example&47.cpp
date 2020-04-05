#include<iostream>
using namespace std;

int NumberOf(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
			number++;
		n = n / 10;
	}
	return number;
}
int NumberOfBetweenAndN(unsigned int n)
{
	int number = 0;
	for (int i = 1; i <= n; i++)
		number += NumberOf(i);
	return number;
}

// ====================²âÊÔ´úÂë====================
void Test(char* testName, int n, int expected)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	if (NumberOfBetweenAndN(n) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	printf("\n");
}

void Test()
{
	Test("Test1", 1, 1);
	Test("Test2", 5, 1);
	Test("Test3", 10, 2);
	Test("Test4", 55, 16);
	Test("Test5", 99, 20);
	Test("Test6", 10000, 4001);
	Test("Test7", 21345, 18821);
	Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
	Test();

	return 0;
}

