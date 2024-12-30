#include "stack.h"

int IsEmpty(Node* S)
{
	return S->Next == NULL;
}

Node* CreateStack(void)
{
	Node* S;
	S = malloc(sizeof(Node));
	if (S == NULL)
	{
		FatalError("Out of space!");
	}
	S->Next == NULL;
	MakeEmpty(S);

	return S;
}

void MakeEmpty(Node* S)
{
	if (S == NULL)
	{
		Error("Must use CreateStack first");
	}
	else
	{
		while (!IsEmpty(S))
			Pop(S);
	}
}

void Push(double X, Node* S)
{
	Node* TmpCell;
	TmpCell = malloc(sizeof(Node));
	if (TmpCell == NULL)
		FatalError("Out of space!!!");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

double Top(Node* S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	Error("Empty stack!");
	return 0;
}

void Pop(Node* S)
{
	Node* FirstCell;
	if (IsEmpty(S))
		Error("Empty stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}