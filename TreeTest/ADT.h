#ifndef __AVL_H__
#define __AVL_H__
#include <stdio.h>

TreeNode* MakeEmpty(TreeNode* T);
TreeNode* Find(double X, TreeNode* T);
TreeNode* FindMin(TreeNode* T);
TreeNode* FindMax(TreeNode* T);
TreeNode* Insert(double X, TreeNode* T);
TreeNode* Delete(double X, TreeNode T);
double Retrieve(TreeNode* P);

typedef struct TreeNode {
	double Element;
	TreeNode* Left;
	TreeNode* Right;
}TreeNode;
#endif
