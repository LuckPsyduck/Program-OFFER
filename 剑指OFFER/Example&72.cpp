#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	unsigned int i = 0;
	list<int> numbers;
	for (i = 0; i < n; i++)
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}

// ====================²âÊÔ´úÂë====================
void Test(int n, int m,int expected)
{
	if (LastRemaining(n, m) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	Test(5, 3, 3);
}
void Test2()
{
	Test(1,1,0);
}
void Test3()
{
	Test(0, 0, -1);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}