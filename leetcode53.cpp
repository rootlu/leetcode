/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int n;
//DP解决，时间复杂度O（n）
//int maxSubArray(int *nums) 
//{
//	//dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0)
//	int *dp = new int[n];//dp[i] 表示以nums[i]结尾的某一段子串的最大和值;
//	dp[0] = nums[0];
//	int max = dp[0];
//
//	for (int i = 1; i < n; i++)
//	{
//		dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
//		if (max < dp[i])
//			max = dp[i];
//	}
//
//	return max;
//}
//分治法O（nlogn）,分成两块.有问题！！！[-1,-2]
int recursionMax(int a[], int left, int right)
{
	int i, j;
	if (left == right)		//base case
		return a[left];;

	int center = (left + right) / 2;
	// //每次递归返回时，该值为该子段的最终左最大子序列和  
	int maxLeftSum = recursionMax(a, left, center);
	//每次递归返回时，该值为该子段的右最大自序列和  
	int maxRightSum = recursionMax(a, center + 1, right);
	//从中间向左扩展求子段的最大子序列和，必然包括子段的最右端数  
	int maxLeftBorderSum = 0, leftBorderSum = 0;

	for (i = center; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (j = center + 1; j <right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}
	int  tmp = maxLeftSum>maxRightSum ? maxLeftSum : maxRightSum;
	if (tmp >= maxLeftBorderSum + maxRightBorderSum) return tmp;
	else return maxLeftBorderSum + maxRightBorderSum;
}

int maxSubArray(int *nums)
{
	int maxV = INT_MIN;
	return recursionMax(nums, 0, n - 1);
}
int main()
{
	n = 2;
	int nums[9] = { -2, 1 };
	cout << maxSubArray(nums) << endl;

	system("pause");
	return 0;
}