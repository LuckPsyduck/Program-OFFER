#include<iostream>
using namespace std;

bool MatchCore(char *, char *);

bool Match(char *str, char *pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	return MatchCore(str, pattern);
}

bool MatchCore(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return MatchCore(str + 1, pattern + 2) || MatchCore(str + 1, pattern) || MatchCore(str, pattern + 2);
		else
			return MatchCore(str, pattern + 2);

	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return MatchCore(str + 1, pattern + 1);
	return false;
}


void main()
{
	char str[] = "aaa";
	char pattern1[] = "ab*ac*a";
	char pattern2[] = "ab*a";
	cout << boolalpha << Match(str, pattern1) << endl;
	cout << boolalpha << Match(str, pattern2) << endl;
}