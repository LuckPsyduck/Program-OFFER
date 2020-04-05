#include<iostream>
using namespace std;

int main()
{
	int count;
	cout << "input count:" << endl;
	cin >> count;
	cout << "input number:" << endl;
	int *p = (int *)malloc(sizeof(int)*count);
	for (int i = 0; i < count; i++)
		cin >> p[i];
	int temp;
	for (int i = 0; i < count; i++)
		if (p[i]<0 || p[i]>count - 1)
			cerr << "error" << endl;;

	for (int i = 0; i < count; i++)
	{
		while (p[i] != i)
		{
			if (p[i] == p[p[i]])
			{ 
				cout << p[i] << endl;
				return 0;
			}
			temp = p[i];
			p[i] = p[temp];
			p[temp] = temp;
		}
	}
}