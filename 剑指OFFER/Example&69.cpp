#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
	vector<int> maxInwindows;
	if (num.size() >= size && size >= 1)
	{
		deque<int> index;
		for (unsigned int i = 0; i < size; i++)
		{
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for (unsigned int i = size; i < num.size(); i++)
		{
			maxInwindows.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxInwindows.push_back(num[index.front()]);
	}
	return maxInwindows;
}

// ====================²âÊÔ´úÂë====================
void Test(char* testName, const vector<int> &num, unsigned int size, const vector<int> &expected)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	if (maxInWindows(num, size) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	printf("\n");
}

void Test1()
{
	vector<int> num = {2,3,4,2,6,2,5,1};
	const vector<int> expected = {4,4,6,6,6,5};
	Test("Test1", num, 3, expected);
}

void Test2()
{
	vector<int> num = { 1,2,3,4,5,6 };
	const vector<int> expected = { 3,4,5,6 };
	Test("Test2", num, 3, expected);
}

void Test3()
{
	vector<int> num = { 6,5,4,3,2,1 };
	const vector<int> expected = { 6,5,4,3};
	Test("Test3", num, 3, expected);
}

void Test4()
{
	vector<int> num = { 1,2,3,4 };
	const vector<int> expected = { 1,2,3,4 };
	Test("Test4", num, 1, expected);
}

void Test5()
{
	vector<int> num = { 1,2,3,4 };
	const vector<int> expected = { 4 };
	Test("Test5", num, 4, expected);
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

