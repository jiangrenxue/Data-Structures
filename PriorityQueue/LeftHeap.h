#ifndef __LEFT_H__
#define __LEFT_H__
#include <stdio.h>

TreeNode* Initialize();
double FindMin(TreeNode* H);
int IsEmpty(TreeNode *H);
TreeNode* Merge(TreeNode* H1, TreeNode *H2);
#define Insert(X, H) (H = Insert1((X), H));
TreeNode* Insert1(double X, TreeNode *H);
TreeNode* DeleteMin1(TreeNode *H);


typedef struct TreeNode
{
	double Element;
	TreeNode* Left;
	TreeNode* Right;
	int Npl;
} TreeNode;

#endif