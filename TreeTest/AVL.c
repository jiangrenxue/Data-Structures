#include "AVL.h"

static int Height(AvlNode* P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

AvlNode* Insert(double X, AvlNode* T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(AvlNode));
		if (T == NULL)
			FatalError("Out of space!!!");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X > T->Right->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

	return T;
}

static AvlNode* SingleRotateWithLeft(AvlNode* K2)
{
	AvlNode* K1;
	
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right) + 1);
	K1->Height = Max(Height(K1->Left), K2->Height)) + 1;

	return K1;
}

static AvlNode* DoubleRotateWithLeft(AvlNode* K3)
{
	K3->Left = SingleRotateWithLeft(K3->Left);

	return SingleRotateWithLeft(K3);
}