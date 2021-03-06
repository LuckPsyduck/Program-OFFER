#include<stdio.h>
#include<math.h>
int g_maxValue = 6;

// ====================����һ====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
	if (number < 1)
		return;

	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;

	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i)
	{
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; ++i)
		Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum,
	int* pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

// ====================���Դ���====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	printf("Test for solution1\n");
	PrintProbability_Solution1(n);

	//printf("Test for solution2\n");
	//PrintProbability_Solution2(n);

	printf("\n");
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(4);

	Test(11);

	Test(0);

	return 0;
}


