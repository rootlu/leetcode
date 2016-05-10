/*
Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
分析：
1、双重循环，时间复杂度！！！
2、一次循环O（n）
3、O（nlogn）
*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;

//int minSubArrayLen(int s, vector<int>& nums)
//{
//	int len = nums.size();
//	int minLen = len;
//	if (len == 0)
//		return 0;
//	int sumNums=0;
//	for (int i = 0; i < len; i++)
//		sumNums += nums[i];
//	if (sumNums < s)
//		return 0;
//	else if (sumNums == s)
//		return len;
//	for (int i = 0; i < len; i++)
//	{
//		int temp = nums[i];
//		if (temp >= s)
//			return 1;
//		else{
//			for (int j = i + 1; j < len; j++)
//			{
//				temp += nums[j];
//				if (temp >= s)
//				{
//					int dif = j - i + 1;
//					minLen = dif < minLen ? dif : minLen;
//				}
//			}
//		}
//	}
//	return minLen;
//}

//O(n)
int minSubArrayLen(int s, vector<int>& nums)
{
	int len = nums.size();
	int minLen = INT_MAX;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		sum += nums[i];
		while (sum>=s)
		{
			minLen = (i - j + 1) < minLen ? (i - j + 1) : minLen;
			sum -= nums[j++];
		}
	}
	return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
	vector<int> nums;
	int s, n;
	while (cin>>n)
	{
		int k;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			nums.push_back(k);
		}
		cin >> s;
		cout << minSubArrayLen(s, nums) << endl;
	}
	system("pause");
	return 0;
}
