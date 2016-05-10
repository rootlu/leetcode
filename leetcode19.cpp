/*
Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.
For example
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
��������
http://www.cnblogs.com/foreverking/articles/2341399.html
�ҵ�������n��Ԫ��˼·��
������˳��n�����ǵ���n������ʵ���Ǿ���-������⡣�����һ�ξ���������߶ε������˵���������
�����ܹ��жϵ�����һ���ڵ㣬��Ϊ����next==NULL���������������ָ�룬���������ǵľ���Ϊn��
��ô������߶ε��Ҷ�ָ��ĩβ�ڵ�ʱ����˽ڵ��ָ������n���ڵ㡣
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
			q->next = p;//���½��嵽*r֮��
		q = p;//βָ��ָ���±�β
	}
	if (q != NULL)
			q->next = NULL;//���ڷǿձ���β���ָ�����ÿ�head=s;
	return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *h1, *h2;
	h1 = head;
	h2 = head;
	for (int i = 0; i < n; i++)
	{
		if (h2 == NULL)
			break; 
		h2 = h2->next;
	}
	if (h2 == NULL)
		return head->next;
	h2 = h2->next;
	while (h2!=NULL)
	{
		h1 = h1->next;
		h2 = h2->next;
	}
	h1->next = h1->next->next;
	return head;
}
void printList(ListNode *head)
{
	while (head!=NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
}
int main()
{
	int n;
	cin >> n;
	ListNode *head;
	head=createList();
	head = removeNthFromEnd(head, n);
	printList(head);
	system("pause");
	return 0;
}