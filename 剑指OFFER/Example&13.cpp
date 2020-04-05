#include<iostream>
using namespace std;


bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathlength, bool* visited)
{
	if (str[pathlength] == '\0')
		return true;
	bool hasPath = false;
	if (row >= 0 && row<rows&&col >= 0 && col<cols\
		&&matrix[row*cols + col] == str[pathlength] && \
		!visited[row*cols + col])
	{
		++pathlength;
		visited[row*cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathlength, visited) || \
			hasPathCore(matrix, rows, cols, row - 1, col, str, pathlength, visited) || \
			hasPathCore(matrix, rows, cols, row + 1, col, str, pathlength, visited) || \
			hasPathCore(matrix, rows, cols, row, col + 1, str, pathlength, visited);
		if (!hasPath)
		{
			--pathlength;
			visited[row*cols + col] = false;
		}
	}
	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows<1 || cols<1 || str == NULL)
		return false;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int pathlength = 0;
	for (int row = 0; row<rows; ++row)
		for (int col = 0; col<cols; ++col)
			if (hasPathCore(matrix, rows, cols, row, col, str, pathlength, visited))
				return true;

	delete[] visited;
	return false;
}

void Test(char *testName, char *matrix, int rows, int cols, char *str, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);
	if (hasPath(matrix, rows, cols, str) == expected)
		printf("passed\n");
	else
		printf("failed\n");
}
/*
ABCE
SFCS
ADEE
*/

/*
ABCCED
*/
void Test1()
{
	char matrix[] = "ABCESFCSADEE";
	char *str = "ABCCED";
	Test("Test1", (char*)matrix, 3, 4, str, true);
}
/*
ABCE
SFCS
ADEE
*/

/*
SEE
*/
void Test2()
{
	char matrix[] = "ABCESFCSADEE";
	char *str = "SEE";
	Test("Test2", (char*)matrix, 3, 4, str, true);
}
/*
ABCE
SFCS
ADEE
*/

/*
ASE
*/
void Test3()
{
	char matrix[] = "ABCESFCSADEE";
	char *str = "ASE";
	Test("Test2", (char*)matrix, 3, 4, str,false);
}

void main()
{
	Test1();
	Test2();
	Test3();
}