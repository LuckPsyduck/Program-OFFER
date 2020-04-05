#include<stdio.h>
#include<math.h>

int countOfIntegers(int digits)//一位数的个数，二位数的个数...
{
	if (digits == 1)
		return 10;
	
	int count = (int)pow(10, digits - 1);
	return 9 * count;
}

int beginNumber(int digits)//一位数的起始值，两位数的起始值
{
	if (digits == 1)
		return 0;
	return (int)pow(10, digits - 1);
}

int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index%digits;
	for (int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}

int digitAtIndex(int index)
{
	if (index < 0)
		return -1;

	int digits = 1;
	while (true)
	{
		int numbers = countOfIntegers(digits);//digits位的数字总数
		if (index < numbers * digits)
			return digitAtIndex(index, digits);
		index -= digits*numbers;
		digits++;
	}
	return -1;
}

// ====================测试代码====================
void Test(int index,int expected)
{
	if (digitAtIndex(index) == expected)
		printf("Pass\n");
	else
		printf("Failed\n");
	printf("\n");
}

int main()
{
	Test(1001,7);
	Test(0, 0);
	Test(1, 1);
	Test(190, 1);
	return 0;
}


