#ifndef __STACKLIST_H__
#define __STACKLIST_H__

#include <stdio.h>

#define EmptyTOS (-1)
#define MinStackSize (5)

int IsEmpty(StackRecord* S);
int IsFull(StackRecord* S);
StackRecord* CreateStack(int MaxElements);
void DisposeStack(StackRecord* S);
void MakeEmpty(StackRecord* S);
void Push(double X, StackRecord* S);
ElementType(StackRecord* S);
void Pop(StackRecord* S);
double TopAndPop(StackRecord* S);

typedef struct {
	int Capacity;
	int TopOfStack;
	double* Array;
}StackRecord;
#endif
