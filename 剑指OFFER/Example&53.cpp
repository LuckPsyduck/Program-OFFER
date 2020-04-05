#include<stdio.h>

/****************方法一*****************/
bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyfound = 0;
	while (uglyfound <index)
	{
		++number;
		if (IsUgly(number))
			++uglyfound;                                                
	}
	return number;
}

/*************方法二*******************/
int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

int GetUglyNumber2(int index)
{
	if (index <= 0)
		return 0;

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyindex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyindex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyindex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyindex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyindex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyindex])
			++pMultiply5;
		++nextUglyindex;
	}
	int ugly = pUglyNumbers[nextUglyindex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

// ====================测试代码====================
void Test(int index, int expected)
{
	if (GetUglyNumber(index) == expected)
		printf("solution1 passed\n");
	else
		printf("solution1 failed\n");

	if (GetUglyNumber2(index) == expected)
		printf("solution2 passed\n");
	else
		printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);

	return 0;
}

