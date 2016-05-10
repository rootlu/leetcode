/*
House Robber
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

思路：动态规划问题
num[]为存储金钱数量的vector
维持一个数组dp[i]，表示在第i家时，能获得的最大收益
状态转移方程：
dp[0]=num[0]
dp[1]=max(num[0],num[1])
dp[i]=max(dp[i-2]+num[i],dp[i-1])
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;

int rob(vector<int>& nums) 
{
	if (nums.empty())
		return 0;
	int len = nums.size();
	vector<int> dp(len, 0);//初始化0
	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1]?nums[0]:nums[1];
	for (int i = 2; i < len; i++)
		dp[i] = dp[i - 1]>(dp[i - 2] + nums[i]) ? dp[i - 1] : (dp[i - 2] + nums[i]);
	return dp[len - 1];
}
int main()
{
	vector<int> moneyVec;
	int n;//用户数量
	cin >> n;
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		moneyVec.push_back(m);
	}
	cout << rob(moneyVec) << endl;
	system("pause");
	return 0;
}
