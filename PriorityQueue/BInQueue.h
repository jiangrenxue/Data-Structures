#ifndef __BINQUEUE_H__
#define __BINQUEUE_H__
#include <stdio.h>
#include <math.h>
typedef struct BinNode
{
	double Element;
	BinNode* LeftChild;
	BinNode* NextSibling;
}BinNode;
typedef struct Collection
{
	int CurrentSize;
	BinNode* TheTrees[];
}Collection;
#endif