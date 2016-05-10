/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int trailingZeroes(int n)
{
	int result = 0;
	for (long long i = 5; n / i>0; i *= 5){
		result += (n / i);
	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	cout << trailingZeroes(n) << endl;
	system("pause");
	return 0;
}