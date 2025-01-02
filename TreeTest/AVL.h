#ifndef __AVL_H__
#define __AVL_H__
#include <stdio.h>

AvlNode* MakeEmpty(AvlNode *T);
AvlNode* Find(double X, AvlNode* T);
AvlNode* FindMin(AvlNode T);
AvlNode* FindMax(AvlNode T);
AvlNode* Insert(double X, AvlNode* T);
AvlNode* Delete(double X, AvlNode* T);
double Retrive(AvlNode* P);

typedef struct AvlNode {
	double Element;
	AvlNode* Left;
	AvlNode* Right;
	int Height;
} AvlNode;

#endif
