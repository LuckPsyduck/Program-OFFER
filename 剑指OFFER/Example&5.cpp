#include<iostream>
using namespace std;

bool Find(int **matrix, int row, int col, int num)
{
	bool found = false;
	if (matrix != nullptr && row > 0 && col > 0)
	{
		int row1 = 0, col1 = col - 1;
		while (row1 < row && col1 > 0)//善于利用while来循环
			if (matrix[row1][col1] == num)
			{
				found = true;
				break;
			}
			else if (matrix[row1][col1] > num)
				--col1;
			else
				++row1;
	}
	return found;
}
void main()
{
	int row, col, **matrix,num;
	cout << "input row:" << endl;
	cin >> row;
	cout << "input col:" << endl;
	cin >> col;
	matrix = (int**)malloc(sizeof(int*) * row);//为二维数组分配3行
	for (int i = 0; i < row; ++i)//为每列分配4个大小空间
		matrix[i] = (int*)malloc(sizeof(int) * col);
	cout << "input numbers: " << endl;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> matrix[i][j];

	cout << "input search number: " << endl;
	cin >> num;
	cout << boolalpha << Find(matrix, row, col, num) << endl;
}





