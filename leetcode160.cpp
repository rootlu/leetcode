/*
Intersection of Two Linked Lists
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
ListNode *createList()
{
	int nums;
	ListNode *head;//ͷָ��
	ListNode *p, *q;  //����ָ��
	head = NULL;    //����ʼΪ��
	q = NULL;//βָ���ֵΪ��
	while (cin >> nums)
	{
		p = (ListNode *)malloc(sizeof(ListNode));//�����½��
		p->val = nums;   //����������ݷ����½�����������
		if (head == NULL)
			head = p;//�½�����ձ�
		else
			q->next = p;//���½��嵽*q֮��
		q = p;//βָ��ָ���±�β
	}
	if (q != NULL)
		q->next = NULL;//���ڷǿձ���β���ָ�����ÿ�head=p;
	return head;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *p, *q;
	p = headA;
	q = headB;
	int lenA = 0, lenB = 0;
	if (p == NULL || q == NULL)
		return NULL;
	while (p)
	{
		p = p->next;
		lenA++;
	}
	while (q)
	{
		q = q->next;
		lenB++;
	}
	if (lenA <= lenB)
	{
		int k = lenB - lenA;
		p = headA;
		q = headB;
		while (k--)
			q = q->next;
	}
	else
	{
		int k = lenA - lenB;
		p = headA;
		q = headB;
		while (k--)
			p = p->next;
	}
	while (p!=q)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}
void printList(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
}
int main()
{
	ListNode *headA, *headB;
	headA = createList();
	headB = createList();

	ListNode *node;
	node = getIntersectionNode(headA, headB);
	cout << node->val << endl;
	//printList(head);
	system("pause");
	return 0;
}