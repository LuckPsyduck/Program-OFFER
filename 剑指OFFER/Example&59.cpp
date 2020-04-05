#include<stdio.h>

int GetNumberSameAsIndex(const int *numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;
	
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (numbers[middle] == middle)
			return middle;

		if (numbers[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}

// ====================测试代码====================
void Test(char* testName, int* data, int length, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (GetNumberSameAsIndex(data, length) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	int data[] = { -3,-1,1,3,5 };
	int expected = 3;

	Test("Test1", data, sizeof(data) / sizeof(int), expected);
}


void Test2()
{
	int data[] = { 1,2,3 };
	int expected = -1;

	Test("Test2", data, sizeof(data) / sizeof(int), expected);
}


void Test3()
{
	int data[] = { 0 };
	int expected = 0;

	Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
	int data[] = { -3,-1,1,3,3 };
	int expected = 3;

	Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
	int data[] = { 1, 2 };
	int expected = -1;

	Test("Test5", data, sizeof(data) / sizeof(int), expected);
}



int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();


	return 0;
}

