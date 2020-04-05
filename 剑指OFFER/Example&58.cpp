#include<stdio.h>

int GetMissingNumber(const int * numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;
	
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (left + right) >>1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
				return middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	if (left == length)
		return length;

	return -1;
}

// ====================测试代码====================
void Test(char* testName, int data[], int length, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	int result = GetMissingNumber(data, length);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
	int data[] = { 1, 2, 3};
	Test("Test1", data, sizeof(data) / sizeof(int),0);
}

// 查找的数组出现在数组的开头
void Test2()
{
	int data[] = { 0,1,3};
	Test("Test2", data, sizeof(data) / sizeof(int), 2);
}

// 查找的数组出现在数组的结尾
void Test3()
{
	int data[] = { 0,1,2,4,5};
	Test("Test3", data, sizeof(data) / sizeof(int), 3);
}

// 查找的数字不存在
void Test4()              //是对的
{
	int data[] = { 0 };
	Test("Test4", data, sizeof(data) / sizeof(int),0);
}


// 鲁棒性测试，数组空指针
void Test5()
{
	Test("Test5", NULL, 0, 0);
}

void main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

}