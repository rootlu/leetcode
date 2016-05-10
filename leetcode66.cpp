/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
���⣺һ��������λ�洢�����λ�洢��i=0,ԭ����1 �������������ǽ�λ
���������ƴ����ӷ�����һ
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	vector<int> res;
	vector<int>::iterator it;
	int k = 1;
	for (int i = digits.size()-1; i >= 0; i--)
	{
		it = res.begin();
		int temp;
		temp=(digits[i] + k) % 10;
		res.insert(it, temp);
		k = ((k + digits[i]) / 10);
	}
	if (k != 0)
	{
		it = res.begin();
		res.insert(it, k);
	}
	return res;
}
int main()
{
	vector<int> num = {1,2,3,4,9};
	vector<int> resultVec;
	resultVec = plusOne(num);
	for (int i = 0; i < resultVec.size(); i++)
		cout << resultVec[i];
	cout << endl;
	system("pause");
	return 0;
}

