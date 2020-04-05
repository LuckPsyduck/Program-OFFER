#include <stdio.h>
#include<math.h>

// ====================��̬�滮====================
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
			A[i] = max;//�ÿռ�����ʱ��
		}
	max = A[len];
	delete[] A;

	return max;
}

// ====================̰���㷨====================
int maxProductAfterCutting_solution2(long int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// �����ܶ�ؼ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;

	// ���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����ӶΡ�
	// ��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2 > 3*1��
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
		printf("���������ӵĳ��ȣ�");
		scanf("%d", &length);
		printf("��̬�滮��-----�������ӵ����˻�Ϊ��%d\n", maxProductAfterCutting_solution1(length));
		printf("̰����-----�������ӵ����˻�Ϊ��%d\n", maxProductAfterCutting_solution2(length));
	}


	return 0;
}
