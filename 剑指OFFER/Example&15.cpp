#include <stdio.h>
#include<math.h>

// ====================动态规划====================
int maxProductAfterCutting_solution1(int len)
{
	if (len < 2)
		return 0;
	if (len == 2)
		return 1;
	if (len == 3)
		return 2;

	int* A = new int[len + 1];
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 3;

	int max;
	for (int i = 4; i <= len; ++i)
		for (int j = 1, max = 0; j <= i / 2; ++j)
		{
			int result = A[j] * A[i - j];
			if (max < result)
				max = result;
			A[i] = max;//用空间来换时间
		}
	max = A[len];
	delete[] A;

	return max;
}

// ====================贪婪算法====================
int maxProductAfterCutting_solution2(long int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// 尽可能多地减去长度为3的绳子段
	int timesOf3 = length / 3;

	// 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
	// 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (long int)(pow(3, timesOf3)) * (long int)(pow(2, timesOf2));
}

int main()
{
	long int length;
	while (1)
	{
		printf("请输入绳子的长度：");
		scanf("%d", &length);
		printf("动态规划法-----各段绳子的最大乘积为：%d\n", maxProductAfterCutting_solution1(length));
		printf("贪婪法-----各段绳子的最大乘积为：%d\n", maxProductAfterCutting_solution2(length));
	}


	return 0;
}
