/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,
	 5
	/ \
   4   8
  /   / \
 11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
给定二叉树和一个和值，判断是否存在一条从根节点到叶子节点的路径之和为给定的和值
递归
输入：1 2 0 3 0 0 4 0 0
建立的二叉树如下：
                 1
             /         \
           2            4
               \
               3
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *createBinTree(TreeNode *t)
{
	int k;
	cin >> k;
	if (k == 0)
		t = NULL;
	else{
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t->val = k;
		t->left = createBinTree(t->left);
		t->right = createBinTree(t->right);
	}
	return t;

}
bool hasPathSum(TreeNode* root, int sum) 
{
	if (root == NULL)
		return false;
	if ((root->val == sum) && (!root->left) && (!root->right))
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

}

int main()
{
	TreeNode *root=NULL;
	root = createBinTree(root);
	int sum;
	while (cin >> sum)
	{
		if (hasPathSum(root, sum))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	system("pause");
	return 0;
}