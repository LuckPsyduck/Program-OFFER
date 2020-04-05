#include<stdio.h>

int MaxDiff(const int *numbers, unsigned int length)
{
	if (numbers == nullptr && length < 2)
		return 0;
	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; ++i)
	{
		if (numbers[i - 1] < min)
			min = numbers[i - 1];

		int currentDiff = numbers[i] - min;
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}

void Test(const int *number,unsigned int length, int expected)
{
	if (MaxDiff(number, length) == expected)
		printf("Pass\n");
	else
		printf("Failed\n");
}

void Test1()
{
	const int number[8] = { 9,11,8,5,7,12,16,14 };
	Test(number, 8, 11);
}

void Test2()
{
	const int number[5] = { 1,2,5,6,9};
	Test(number, 5, 8);
}

void Test3()
{
	const int number[5] = { 9,1,2,5,6};
	Test(number,5,5);
}

void Test4()
{
	const int number[2] = {2,10 };
	Test(number,2,8);
}

void Test5()
{
	const int *number = nullptr;
	Test(number, 0, 0);
}


void main()
{
	 Test1();
	 Test2();
	 Test3();
	 Test4();
	 Test5();
}