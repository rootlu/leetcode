/*
Two Sum
题意：给定一个整型数组，一个target，返回和为target的两个元素的下标，只有一组解
思路：
法一：两次循环，时间复杂度O（n^2）,太慢
法二：值和下标存到hash_map中,排序值,时间复杂度O（nlogn）,提升10倍+
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>//STL
using namespace std;

//法一：双重循环
//vector<int> twoSum(vector<int>& nums, int target)
//{
//	vector<int> result;
//	for (int i = 0; i < nums.size(); i++)
//		for (int j = i + 1; j < nums.size(); j++)
//		{
//			if (nums[i] + nums[j] == target)
//			{
//				result.push_back(i);
//				result.push_back(j);
//				return result;
//			}
//		}
//	return result;
//}
//法二：
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	unordered_map<int, int> hashMap;
	for (int i = 0; i < nums.size(); i++)
	{
		int k = target - nums[i];
		
		if (hashMap.find(k) != hashMap.end())//先查找！！再存到hash_map
		{
			result.push_back(hashMap[k]);
			result.push_back(i);
			return result;
		}
		hashMap[nums[i]] = i;//键为元素，值为下标，
	}
	return result;
}
int main()
{
	vector<int> vec,resultVec;
	vec = { 3,2,4 };
	int t = 6;
	resultVec=twoSum(vec, t);
	for (int i = 0; i < resultVec.size(); i++)
		cout << resultVec[i]<<" ";
	cout << endl;
	system("pause");
	return 0;
}