#include"iostream"
using namespace std;

void ReplaceBlank(char string[], int length)
{
	if (string == nullptr || length == 0)
		exit(EXIT_FAILURE);
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i++] != '\0')
	{
		++originalLength;
		if (isspace(string[i]))
			++numberOfBlank;	
	}
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		exit(EXIT_FAILURE);
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (isspace(string[indexOfOriginal]))
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
			string[indexOfNew--] = string[indexOfOriginal];
		--indexOfOriginal;
	}
	cout << "change data:" << endl;
	for (int i = 0; i < newLength; i++)
		cout << string[i] << " ";
	cout << endl;
}

void main()
{
	char string[20] = "I Love You!";
	ReplaceBlank(string, 20);
}