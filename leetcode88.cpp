/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

void merge(int *nums1, int m, int *nums2, int n)
{
	int i = m-1,j = n-1;
	int k = m + n - 1;
	while (i>=0&&j>=0)
	{
		if (nums1[i] <= nums2[j])
			nums1[k--] = nums2[j--];
		else
			nums1[k--] = nums1[i--];
	}
	while (i >=0)
	{
		nums1[k--] = nums1[i--];
	}
	while (j>=0)//取到等于！！
	{
		nums1[k--] = nums2[j--];
	}
	for (int i = 0; i < m + n; i++)
		cout << nums1[i]<<" ";
	cout << endl;
}
int main()
{
	int m, n;
	m = 8;
	n = 6;
	int nums1[1024] = { 1, 2, 3, 4, 5, 5, 6, 8 };
	int nums2[20] = { 5, 7, 9, 10, 23, 45 };
	merge(nums1, m, nums2, n);

	system("pause");
	return 0;
}