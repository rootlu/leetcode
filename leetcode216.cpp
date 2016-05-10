/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.
Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
题意：从1-9这9个数中，选出k个数，和为n，每个数不等，且递增
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void caculate(vector<vector<int>>&res,vector<int> &item, int max, int k, int left)
{
	if (item.size() == k&&left == 0)
	{
		res.push_back(item);
		return;
	}
	for (int i = max + 1; i <= 9 && i <= left; i++)
	{
		item.push_back(i);
		caculate(res, item, i, k, left - i);
		item.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) 
{
	vector<vector<int>> res;
	vector<int> item;

	caculate(res,item, 0, k, n);
	return res;
}
int main()
{
	vector<vector<int>> result;
	int k, n;
	cin >> k >> n;
	result = combinationSum3(k, n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
			cout << result[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}