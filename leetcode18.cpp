/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.
Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
思路；
先对原序列排序，然后依次每四个元素相加，判断 是否满足条件，时间复杂度
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
	vector<vector<int>> res;
	if (nums.size() == 0)
		return res;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	for (int i = 0; i < len; i++){
		int target3 = target - nums[i];
		for (int j = i + 1; j < len; j++){
			int target2 = target3 - nums[j];
			int left = j + 1;
			int right = len - 1;
			while (left<right){
				int twoSum = nums[left] + nums[right];
				if (twoSum < target2)
					left++;
				else if (twoSum>target2)
					right--;
				else{
					vector<int> item;
					item.push_back(nums[i]);
					item.push_back(nums[j]);
					item.push_back(nums[left]);
					item.push_back(nums[right]);
					res.push_back(item);

					while (left < right&&nums[left] == item[2])
						left++;
					while (left < right&&nums[right] == item[3])
						right--;
				}
			}
			while (j + 1 < len && nums[j + 1] == nums[j]) //连续重复
				++j;
		}
		while (i + 1 < len && nums[i + 1] == nums[i]) 
			++i;
	}
	return res;
}
int main()
{
	vector<int> s;
	vector<vector<int>> result;
	int target ;
	int n;
	while (cin>>n)
	{
		int k;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			s.push_back(k);
		}
		cin >> target;
		result = fourSum(s, target);
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[0].size(); j++)
				cout << result[i][j] << " ";
			cout << endl;
		}
	}
	
	system("pause");
	return 0;
}