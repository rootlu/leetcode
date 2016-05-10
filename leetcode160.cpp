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
	ListNode *head;//头指针
	ListNode *p, *q;  //工作指针
	head = NULL;    //链表开始为空
	q = NULL;//尾指针初值为空
	while (cin >> nums)
	{
		p = (ListNode *)malloc(sizeof(ListNode));//生成新结点
		p->val = nums;   //将读入的数据放入新结点的数据域中
		if (head == NULL)
			head = p;//新结点插入空表
		else
			q->next = p;//将新结点插到*q之后
		q = p;//尾指针指向新表尾
	}
	if (q != NULL)
		q->next = NULL;//对于非空表，将尾结点指针域置空head=p;
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