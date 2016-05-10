/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
²ã´Î±éÀú
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<vector<char>> res;

struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *createBinTree(TreeNode *t)
{
	char c;
	cin >> c;
	if (c == '#')
		t = NULL;
	else{
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t->val = c;
		t->left = createBinTree(t->left);
		t->right = createBinTree(t->right);
	}
	return t;
}
void DFS(TreeNode *root, int level)
{
	if (root == NULL)
		return;
	if (level == res.size())
		res.push_back(vector<char>());
	res[level].push_back(root->val);
	DFS(root->left, level + 1);
	DFS(root->right, level + 1);
}
vector<vector<char>> levelOrder(TreeNode* root)
{
	DFS(root, 0);
	return res;
}
void printBinTree(vector<vector<char>> tree)
{
	for (int i = 0; i < tree.size(); i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
			cout << tree[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	TreeNode *root=NULL;
	root = createBinTree(root);
	vector<vector<char>> result;
	result = levelOrder(root);
	printBinTree(res);
	system("pause");
	return 0;
}