#include "list.h"

int IsLast(Node* P, Node* L)
{
	return P->P == NULL;
}

Node* Find(double X, Node* L)
{
	Node* P;
	P = L->P;
	while (P != NULL && P->value != X)
	{
		P = P->P;
	}
	return P;
}

void Delete(double X, Node* L)
{
	Node* P, * TmpCell;
	
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->P;
		P->P = TmpCell->P;
		free(TmpCell);
	}
}

Node* FindPrevious(double X, Node* L)
{
	Node* P;

	P = L;
	while (P->P != NULL && P->P->value != X)
	{
		P = P->P;
	}
	return P;
}

void Insert(double X, Node* L, Node* P)
{
	Node* TmpCell;

	TmpCell = malloc(sizeof(Node));
	if (TmpCell == NULL)
	{
		FatalError("Out of space!");
	}
	TmpCell->value = X;
	TmpCell->P = P->P;
	P->P = TmpCell;
}

void DeleteList(Node* L)
{
	Node* P;
	
	P = L->P;
	L->P = NULL;
	while (P != NULL)
	{
		free(P);
		P = P->P;
	}
}

void DeleteList(Node* L)
{
	Node* P, * Tmp;
	P = L->P;
	L->P = NULL;
	while (P != NULL)
	{
		Tmp = P->P;
		free(P);
		P = Tmp;
	}
}