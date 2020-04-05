#include<iostream>
using namespace std;
int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		exit(EXIT_FAILURE);
	int count = 0;
	for (int i = 0; i < length; i++)
		if (numbers[i] >= start&&numbers[i] <= end)
			++count;
	return count;
}

int getDuplication(const int *numbers,int length)
{
	if (numbers == nullptr || length <= 0)
		cerr << "error" << endl;
	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) / 2) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
			if (count > 1)
				return start;
			else
				break;
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

void main()
{
	int count;
	cout << "input count:" << endl;
	cin >> count;
	cout << "input number:" << endl;
	int *p = (int *)malloc(sizeof(int)*count);
	for (int i = 0; i < count; i++)
		cin >> p[i];
	cout << getDuplication(p, count) << endl;
}