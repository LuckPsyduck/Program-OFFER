#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int LongestSubstringWithoutDuplication(const string &str)
{
	int curLength = 0;
	int maxLength = 0;

	int *position = new int[26];
	for (int i = 0; i < 26; i++)
		position[i] = -1;
	for (int i = 0; i < str.length(); i++)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex <0 || i - prevIndex >curLength)
			++curLength;
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;
			curLength = i - prevIndex;
		}
		position[str[i] - 'a'] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	delete[] position;
	return maxLength;
}
// ====================≤‚ ‘¥˙¬Î====================
void Test(char* testName, const string &str, int number)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	if (LongestSubstringWithoutDuplication(str) == number)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.\n");

	printf("\n");
}

void Test1()
{
	string str = "arabcacfr";
	Test("Test1", str, 4);
}

void Test2()
{
	string str = "aaaaaa";
	Test("Test2", str, 1);
}

void Test3()
{
	string str = "a";
	Test("Test3", str, 1);
}

void Test4()
{
	string str = "abcde";
	Test("Test4", str, 5);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}

