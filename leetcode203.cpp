/*
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
ListNode *createList(int *nums,int n)
{
	ListNode *head;
	ListNode *p, *q;
	head = NULL;
	q = NULL;
	for (int i = 0; i < n;i++)
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
ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL) 
		return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}
void printList(ListNode *head)
{
	while (head!=NULL)
	{
		cout << head->val<<" ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	ListNode *head;
	int nums[] = { 1, 2, 3, 4, 4, 4, 5, 6 };
	int n = 8;
	head = createList(nums,n);
	int val;
	cin >> val;
	head = removeElements(head, val);
	printList(head);
	system("pause");
	return 0;
}