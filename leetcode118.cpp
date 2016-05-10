/*
´òÓ¡Ñî»ÔÈý½Ç
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> result(numRows);
	for (int i = 0; i < numRows; i++)
	{
		result[i].resize(i + 1);
		result[i][0] = result[i][i] = 1;
		for (int j = 1; j < i; j++)
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> pascalTri;
	pascalTri = generate(n);
	for (int i = 0; i < pascalTri.size();i++)
	{
		for (int j = 0; j < pascalTri[i].size();j++)
			cout << pascalTri[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}