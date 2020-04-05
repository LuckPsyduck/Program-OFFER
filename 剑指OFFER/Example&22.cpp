#include<iostream>
using namespace std;

bool scanUnsignedInteger(const char ** str)
{
	const char *before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
	return *str > before;
}

bool scanInteger(const char **str)
{
	if (**str == '+' || **str == '-')
		++(*str);
	return scanUnsignedInteger(str);
}

bool isNumeric(const char *str)
{
	if (str == nullptr)
		return false;

	bool numeric = scanInteger(&str);
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);
	}
	return numeric && *str == '\0';                                      
}

int main()
{
	cout << boolalpha << isNumeric("5e2") << endl;
	cout << boolalpha << isNumeric("12e") << endl;
	cout << boolalpha << isNumeric("1a3.14") << endl;
	cout << boolalpha << isNumeric("+-5") << endl;
	return 0;

}