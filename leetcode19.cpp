/*
Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.
For example
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
单链表建立
http://www.cnblogs.com/foreverking/articles/2341399.html
找到倒数第n个元素思路：
不管是顺数n个还是倒数n个，其实都是距离-标尺问题。标尺是一段距离可以用线段的两个端点来衡量，
我们能够判断倒数第一个节点，因为他的next==NULL。如果我们用两个指针，并保持他们的距离为n，
那么当这个线段的右端指向末尾节点时，左端节点就指向倒数第n个节点。
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
			q->next = p;//将新结点插到*r之后
		q = p;//尾指针指向新表尾
	}
	if (q != NULL)
			q->next = NULL;//对于非空表，将尾结点指针域置空head=s;
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