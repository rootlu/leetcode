/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
题意：当且仅当nums[i]==nums[j],并且|i-j|<=k，返回true
*/
#include<iostream>
#include<stdlib.h>
#include<unordered_set>
using namespace std;
int n;
bool containsNearbyDuplicate(int *nums, int k) 
{
	unordered_set<int> s;

	if (k <= 0) return false;
	if (k >= n) k = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (i > k) s.erase(nums[i - k - 1]);
		if (s.find(nums[i]) != s.end()) return true;
		s.insert(nums[i]);
	}

	return false;
}
int main()
{
	while (cin >> n)
	{
		int *nums = new int[n];
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		int k;
		cin >> k;
		cout << containsNearbyDuplicate(nums, k) << endl;
	}
	system("pause");
	return 0;
}