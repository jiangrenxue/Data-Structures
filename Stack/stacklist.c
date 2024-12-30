#include "StackList.h"

StackRecord* CreateStack(int MaxElements)
{
	StackRecord* S;
	if (MaxElements < MinStackSize)
		Error("Stack size is too small!");
	S = malloc(sizeof(StackRecord));
	if (S == NULL)
		FatalError("Out of space!");
	S->Array = malloc(sizeof(double) * MaxElements);
	if (S->Array == NULL)
		FatalError("Out of space!!!");
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(StackRecord* S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

int IsEmpty(StackRecord* S)
{
	return S->TopOfStack == EmptyTOS;
}

void MakeEmpty(StackRecord* S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(double X, StackRecord* S)
{
	if (IsFull(S))
		Error("Full Stack!");
	else
		S->Array[++S->TopOfStack] = X;
}

double Top(StackRecord* S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	Error("Empty stack!");
	
	return 0;
}

void Pop(StackRecord* S)
{
	if (IsEmpty(S))
	{
		Error("Empty stack!");
	}
	else
		S->TopOfStack--;
}

double TopAndPop(StackRecord* S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	Error("Empty stack!");

	return 0;
}