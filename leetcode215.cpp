/*
Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int nums[] = { 3, 2, 1, 5, 6, 4 };
int n = 6;
//¿ìËÙÅÅĞò
void QSort(int *nums, int left, int right)
{
	int i, j;
	if (left < right)
	{
		i = left;
		j = right + 1;
		do{
			do {
				i++;
			} while (nums[i] < nums[left]);
			do {
				j--;
			}while (nums[j] > nums[left]);
			if (i < j)
			{
				int temp1 = nums[i];
				nums[i] = nums[j];
				nums[j] = temp1;
			}
		} while (i < j);
		int temp2 = nums[left];
		nums[left] = nums[j];
		nums[j] = temp2;
		QSort(nums, left, j - 1);
		QSort(nums, j + 1, right);
	}
}
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int findKthLargest(int *nums, int k)
{
	if (n == 0)
		return 0;
	qsort(nums,n,sizeof(int),cmp);
	//QSort(nums, 0, n - 1);
	return nums[n - k];
}
int main()
{
	int k;
	cin >> k;
	cout << findKthLargest(nums, k) << endl;

	system("pause");
	return 0;
}