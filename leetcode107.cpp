/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
vector<vector<int> > res;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBinTree(TreeNode *t)
{
	char c;
	c = getchar();
	if (c== '#')
		t = NULL;
	else{
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t->val =c;
		t->left=createBinTree(t->left);
		t->right=createBinTree(t->right);
	}
	return t;
}
void DFS(TreeNode* root, int level)
{
	if (root == NULL) return;
	if (level == res.size()) // The level does not exist in output
	{
		res.push_back(vector<int>()); // Create a new level
	}

	res[level].push_back(root->val); // Add the current value to its level
	DFS(root->left, level + 1); // Go to the next level
	DFS(root->right, level + 1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	DFS(root, 0);
	return vector<vector<int> >(res.rbegin(), res.rend());
}
//vector<vector<int>> levelOrderBottom(TreeNode* root) 
//{
//	vector<vector<int>> result;
//	if (root == NULL)
//		return result;
//	vector<vector<int>>::iterator it = result.begin();
//	vector<TreeNode *> que;
//	que.push_back(root);
//	int cur = 0;
//	int last = 1;
//	while (cur<que.size())
//	{
//		vector<int> item;
//		last = que.size();
//		while (cur < last)
//		{
//			item.push_back(que[cur]->val);
//			if (que[cur]->left)
//				que.push_back(que[cur]->left);
//			if (que[cur]->right)
//				que.push_back(que[cur]->right);
//			cur++;
//		}
//		result.insert(it, item);
//	}
//
//	return result;
//}
int main()
{
	TreeNode *t = NULL;
	t=createBinTree(t);
	vector<vector<int>> result;
	result = levelOrderBottom(t);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
			cout << res[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}