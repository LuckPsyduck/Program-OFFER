#include<iostream>
using namespace std;

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num&1)==0)&&(indexBit < 8*sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumbersAppearsOnce(int data[], int length)
{
	if (data == nullptr || length < 2)
		return;

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; i++)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	int num1, num2;
	num1 = num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
			num1 ^= data[j];
		else
			num2 ^= data[j];
	}
	cout << num1 << " " << num2 << endl;
}


void main()
{
	int data[] = { 2,4,3,6,3,2,5,5 };
	FindNumbersAppearsOnce(data, 8);
}





//#include<iostream>
//using namespace std;
//
//
//int FindNumberAppearingOnce(int number[], int length)
//{
//	if (number == nullptr || length <= 0)
//		cerr << "error" << endl;
//
//	int bitSum[32] = { 0 };
//	for (int i = 0; i < length; ++i)
//	{
//		int bitMask = 1;
//		for (int j = 31; j >= 0; --j)
//		{
//			int bit = number[i] & bitMask;
//			if (bit != 0)
//				bitSum[j] += 1;
//			bitMask = bitMask << 1;
//		}
//	}
//	int result = 0;
//	for (int i = 0; i < 32; ++i)
//	{
//		result = result << 1;
//		result += bitSum[i] % 3;
//	}
//	return  result;
//}
//
//void main()
//{
//	int data[] = { 3,3,3,1 };
//	cout << FindNumberAppearingOnce(data, 4) << endl;
//}