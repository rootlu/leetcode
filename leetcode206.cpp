/*
Reverse a singly linked list.
1���½�һ������
2��ԭ�����������ת������
http://www.2cto.com/kf/201110/106607.html
3���ݹ�
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
//��ͨ����ʵ������,����
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
//�ݹ�ʵ��
ListNode *reverseList(ListNode *head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	else
	{
		ListNode *currentHead, *headNext;
		currentHead = head;//��¼��ǰ��ͷ�ڵ�a0
		headNext = head->next;//��¼��ǰͷ�ڵ�de�����ڵ�a1
		head = reverseList(headNext);//����a1----an��ת���ͷ�ڵ�
		headNext->next = currentHead;//�����汣��ĵ�ַ����ת���β��㣩ָ��ԭ����ͷ���a0
		currentHead->next = NULL;//��a0��next������
	}
	return head;//����a0
}


	}
	
}
int main()
{

	system("pause");
	return 0;
}