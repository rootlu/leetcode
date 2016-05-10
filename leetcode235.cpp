/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
ע���Ƕ������������Ƚ�����
�Ƚ�p,q��root�Ĵ�С
��p,q������root,����LCA�����������ϣ�
��p,q��С��root����LCA�����������ϣ�
��p,qһ��һС����LCA��Ϊroot
��Ҫע����ǣ��ж�һ��һСʱ��Ҫ�ü����ж�
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

TreeNode *root;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}}
};
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL)
		return NULL;
	if ((root->val - p->val)*(root->val - q->val) <= 0)
		return root;
	else if ((root->val > p->val) && (root->val > q->val))
		return lowestCommonAncestor1(root->left, p, q);
	else
		return lowestCommonAncestor1(root->right, p, q);
}
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
��ͨ������
�����ڵ㣬�ҵ�p,ͬʱ��¼�´�root���ü�����·����Ȼ��Ƚ�·�������һ����ȵĽڵ����LCA
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL)
		return NULL;
	vector<TreeNode *> pPath;
	vector<TreeNode *> qPath;
	pPath.push_back(root);
	qPath.push_back(root);

	getPath(root, p, pPath);
	getPath(root, q, qPath);

	int len1 = pPath.size();
	int len2 = qPath.size();
	int i, j;
	for (i = 0, j = 0; i<len1&&j<len2; i++, j++)
	{
		if (pPath[i] != qPath[j])
			break;
	}
	return pPath[i - 1];
}
bool getPath(TreeNode* root, TreeNode* n, vector<TreeNode*> &path)//ע���Ǵ����ã�������ܻ�Memory Limit Exceeded
{
	path.push_back(root);
	if (root == n)
		return true;
	if (root->left != NULL)
	{
		if (getPath(root->left, n, path))
			return true;
		path.pop_back();
	}
	if (root->right != NULL)
	{
		if (getPath(root->right, n, path))
			return true;
		path.pop_back();
	}

	return false;
}


int main()
{
	

	system("pause");
	return 0;
}
