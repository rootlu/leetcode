/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
注意是二叉搜索树，比较容易
比较p,q和root的大小
若p,q都大于root,，则LCA必在右子树上；
若p,q都小于root，则LCA必在左子树上；
若p,q一大一小，则LCA必为root
需要注意的是：判断一大一小时，要用减法判断
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
普通二叉树
遍历节点，找到p,同时记录下从root到该几点点的路径，然后比较路径，最后一个相等的节点就是LCA
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
bool getPath(TreeNode* root, TreeNode* n, vector<TreeNode*> &path)//注意是传引用，否则可能会Memory Limit Exceeded
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
