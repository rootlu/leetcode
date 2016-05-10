/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int n = 3;
void rotate(int *nums, int k)
{
	k = n%k;//取余！！，旋转次数大于长度
	int *temp = new int[k];
	int j = 0;
	for (int i = n - k; i <n; i++)
		temp[j++] = nums[i];
	for (int i = n-k-1; i >=0; i--)
	{
		nums[i+k] = nums[i];
	}
	for (int i = 0; i < k; i++)
		nums[i] = temp[i];

	for (int i = 0; i < n; i++)
		cout << nums[i];

}

int main()
{
	int nums[] = { 1, 2, 3 };
	int k=2;
	rotate(nums, k);
	system("pause");
	return 0;
}