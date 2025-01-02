// Tree
#include <stdio.h>


void ListDirectory(DirectoryOrFile D)
{
	ListDir(D, 0);
}

static void ListDir(DirectoryOrFile D, int Depth)
{
	if (D is a Legitimate entry)
	{
		PrintName(D, Depth);
		if (D is a directory)
			for each child, C, of D
				ListDir(C, depth + 1);
	}
}

static void SizeDirectory(DirectoryOrFile D)
{
	int TotalSize;

	TotalSize = 0;
	if (D is a legitimate entry)
	{
		TotalSize = FileSize(D);
		if (D is a directory)
			for each child, C of D
				TotalSize += SizeDirectory(C);
	}
	return TotalSize;
}




typedef struct TreeNode {
	double Element;
	TreeNode* FirstChild;
	TreeNode* NextSibling;
} TreeNode;


// Binary Tree
typedef struct TreeNode {
	double Element;
	TreeNode* Left;
	TreeNode* Right;
}TreeNode;

void PrintTree(TreeNode* T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		PrintElement(T->Element);
		PrintTree(T->Right);
	}
}

int Height(TreeNode* T)
{
	if (T == NULL)
		return -1;
	else
		return 1 + MAX(Height(T->Left), Height(T->Right));

}
