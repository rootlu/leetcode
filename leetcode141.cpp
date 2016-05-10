/*
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
������˫ָ��p.q��pһ���ƶ�һ����q�ƶ�����
���ڻ���p��q����������q�ȵ���NULL
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *createList(int* nums,int n)
{
	ListNode *head;
	ListNode *p, *q;
	head = NULL;
	q = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->val = nums[i];
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	}
	if (q != NULL)
		q->next = NULL;
	return head;
}
bool hasCycle(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return false;
	ListNode *p, *q;
	p = head;
	q = head;
	while (q->next != NULL&&q->next->next != NULL)
	{

		p = p->next;
		q = q->next->next;
		if (p == q)
			return true;
	}
	return false;
}
int main()
{
	int nums[] = { 1, 2, 3, 4, 5 };
	int n = 5;
	ListNode *head;
	head = createList(nums, n);
	if (hasCycle(head))
		cout << "�л�" << endl;
	else
		cout << "�޻�" << endl;
	system("pause");
	return 0;
}