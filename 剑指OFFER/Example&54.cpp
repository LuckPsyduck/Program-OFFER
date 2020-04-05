#include<stdio.h>

char FirstNotRepeatingChar(char *pString)
{
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[256];
	for (int i = 0; i < tableSize; i++)
		hashTable[i] = 0;

	char *pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)]++;

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}

// ====================���Դ���====================
void Test(char* pString, char expected)
{
	if (FirstNotRepeatingChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	// ����������ԣ�����ֻ����һ�ε��ַ�
	Test("google", 'l');

	// ����������ԣ�������ֻ����һ�ε��ַ�
	Test("aabccdbd", '\0');

	// ����������ԣ������ַ���ֻ����һ��
	Test("abcdefg", 'a');

	// ³���Բ��ԣ�����NULL
	Test(NULL, '\0');

	return 0;
}