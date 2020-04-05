#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(const int *pPush,const int *pPop,int nLength)
{
	bool bpossible = false;
	if (pPush != nullptr && pPop != nullptr && nLength > 0)
	{
		const int* pNextpush = pPush;
		const int* pNextpop = pPop;

		stack<int>stackData;
		while (pNextpop - pPop < nLength)
		{
			while (stackData.empty() || stackData.top() != *pNextpop)
			{
				if (pNextpush - pPush == nLength)
					break;
				stackData.push(*pNextpush);
				pNextpush++;
			}
			if (stackData.top() != *pNextpop)
				break;

			stackData.pop();
			pNextpop++;
		}
		if (stackData.empty() && (pNextpop - pPop == nLength))
			bpossible = true;
	}
	return bpossible;
}

// ====================测试代码====================
void Test(char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop, nLength, true);
}

void Test2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, nLength, true);
}

void Test3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, nLength, false);
}

void Test4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test("Test5", push, pop, nLength, false);
}

void Test6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test("Test6", push, pop, nLength, true);
}

void Test7()
{
	Test("Test7", NULL, NULL, 0, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}

