#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int GetMaxValue_solution(const int * values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return 0;

	int **maxValues = new int*[rows];
	for (int i = 0; i < rows; i++)
		maxValues[i] = new int[cols];

	for (int i=0;i<rows;i++)
		for (int j = 0; j < cols; j++)
		{
			int left = 0;
			int up = 0;
			if (i > 0)
				up = maxValues[i - 1][j];
			if (j > 0)
				left = maxValues[i][j - 1];

			maxValues[i][j] = max(left, up) + values[i*cols + j];
		}
	int maxvalue = maxValues[rows - 1][cols - 1];

	for (int i = 0; i < rows; i++)
		delete[] maxValues[i];
	delete[] maxValues;

	return maxvalue;
}

// ====================²âÊÔ´úÂë====================
void Test(char* testName, int* numbers, int rows,int cols,int expectedResult)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	if (expectedResult == GetMaxValue_solution(numbers,rows,cols))
		printf("Expected result is: %d\n", expectedResult);

	printf("\n");
}

void Test1()
{
	int numbers[] = { 1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
	Test("Test1", numbers,4,4, 53);
}

void Test2()
{
	int numbers[] = { 1,2,3 };
	Test("Test2", numbers, 1,3, 6);
}

void Test3()
{
	int numbers[] = { 1,2,3 };
	Test("Test3", numbers, 3, 1, 6);
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers,1, 1, 1);
}



void main()
{
	Test1();
	Test2();
	Test3();
	Test4();
}