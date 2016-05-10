/*
Write an efficient algorithm that searches for a value in an mXn matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int m, n;
int **a = NULL;
bool searchMatrix(int **a, int target)
{
	int i = 0, j = n - 1;
	while (i<m&&j>=0)
	{
		if (a[i][j] < target)
			i++;
		else if (a[i][j] > target)
			j--;
		else
			return true;
	}
	return false;
}
int main()
{
	cin >> m>>n;
	a = new int *[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int target;
	while (cin >> target)
	{
		if (searchMatrix(a, target))
			cout << target << " is existed!" << endl;
		else
			cout << target << " is not existed!" << endl;
	}

	system("pause");
	return 0;
}