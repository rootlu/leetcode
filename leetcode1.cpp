/*
Two Sum
���⣺����һ���������飬һ��target�����غ�Ϊtarget������Ԫ�ص��±ֻ꣬��һ���
˼·��
��һ������ѭ����ʱ�临�Ӷ�O��n^2��,̫��
������ֵ���±�浽hash_map��,����ֵ,ʱ�临�Ӷ�O��nlogn��,����10��+
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>//STL
using namespace std;

//��һ��˫��ѭ��
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
//������
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	unordered_map<int, int> hashMap;
	for (int i = 0; i < nums.size(); i++)
	{
		int k = target - nums[i];
		
		if (hashMap.find(k) != hashMap.end())//�Ȳ��ң����ٴ浽hash_map
		{
			result.push_back(hashMap[k]);
			result.push_back(i);
			return result;
		}
		hashMap[nums[i]] = i;//��ΪԪ�أ�ֵΪ�±꣬
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