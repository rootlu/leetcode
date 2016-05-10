/*
Reverse a singly linked list.
1、新建一个链表
2、原链表基础上逆转，迭代
http://www.2cto.com/kf/201110/106607.html
3、递归
http://www.2cto.com/kf/201409/337152.html
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
//普通方法实现逆置,迭代
ListNode *reverseList(ListNode *head)
{
	ListNode *p,*q, *r;
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	p = head;
	q = head->next;
	head->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}
//递归实现
ListNode *reverseList(ListNode *head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	else
	{
		ListNode *currentHead, *headNext;
		currentHead = head;//记录当前的头节点a0
		headNext = head->next;//记录当前头节点de后续节点a1
		head = reverseList(headNext);//返回a1----an逆转后的头节点
		headNext->next = currentHead;//用上面保存的地址（逆转后的尾结点）指向原来的头结点a0
		currentHead->next = NULL;//将a0的next域置零
	}
	return head;//返回a0
}


	}
	
}
int main()
{

	system("pause");
	return 0;
}