#include "ADT.h"

TreeNode* MakeEmpty(TreeNode* T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

TreeNode* Find(double X, TreeNode* T)
{
	if (T == NULL)
	{
		return NULL;
	}
	if (X < T->Element)
		return Find(X, T->Left);
	else if	(X > T->Element)
		return Find(X, T->Right);
	else 
		return T;
}

TreeNode* FindMin(TreeNode* T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

TreeNode* FindMax(TreeNode* T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}

TreeNode* Insert(double X, TreeNode* T)
{
	if (T != NULL)
	{
		T = malloc(sizeof(TreeNode));
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
	}

	return T;
}

TreeNode* Delete(double X, TreeNode* T)
{
	TreeNode* TmpCell;
	if (T == NULL)
		Error("Element not found!");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Left);
	else if (T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Right == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}

	return T;
}