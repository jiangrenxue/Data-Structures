#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>

int IsEmpty(Node *S);
Node* CreateStack(void);
void DisposeStack(Node *S);
void Push(double X, Node *S);
double Top(Node* S);

typedef struct Node{
	double Element;
	Node* Next;
} Node;
#endif