/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>

using namespace std;
int majorityElement(vector<int>& nums)
{
	vector<int>::size_type len = nums.size();
	map<int, int> mapNums;
	for (int i = 0; i < len; i++)
		mapNums[nums[i]]++;
	map<int, int>::iterator it = mapNums.begin();
	while (it!=mapNums.end())
	{
		if (it->second > len / 2)
			 return it->first;
		it++;
	}
}
int main()
{
	vector<int> vecNums;
	vecNums = { 1, 2, 2, 3, 3, 3, 3, 3, 5 };
	cout << majorityElement(vecNums) << endl;
	system("pause");
	return 0;
}