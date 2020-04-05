#include<stdio.h>

enum Status
{
	kValid = 0,kInvalid
};
int g_nStatus = kValid;

long long StrToInCore(const char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0'&&*digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*digit - '\0');
			if (!minus&&num > 0x7FFFFFFF || (minus&&num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
		g_nStatus = kValid;
	return num;
}

int StrToInt(const char *str)
{
	g_nStatus = kInvalid;
	long long num = 0;
	if (str != nullptr&&*str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if(*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
			num = StrToInCore(str, minus);
	}
	return (int)num;
}

// ====================���Դ���====================
void Test(char* string)
{
	int result = StrToInt(string);
	if (result == 0 && g_nStatus == kInvalid)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
	Test(NULL);

	Test("");

	Test("123");

	Test("+123");

	Test("-123");

	Test("1a33");

	Test("+0");

	Test("-0");

	//��Ч�����������, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//��Ч����С������, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");

	return 0;
}