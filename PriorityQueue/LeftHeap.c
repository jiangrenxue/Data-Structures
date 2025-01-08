#include "LeftHeap.h"

TreeNode* Merge(TreeNode* H1, TreeNode* H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge(H2, H1);
}

static TreeNode* Merge1(TreeNode* H1, TreeNode* H2)
{
	if (H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

TreeNode* Insert1(double X, TreeNode* H)
{
	TreeNode* SingleNode;
	SingleNode = malloc(sizeof(TreeNode));
	if (SingleNode == NULL)
		FatalError("Out of Space!!!");
	else
	{
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}

TreeNode* DeleteMin1(TreeNode *H)
{
	TreeNode* LeftHeap, *RightHeap;

	if (IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H;
	}

	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);

	return Merge(LeftHeap, RightHeap);
}