#include "BinHeap.h"

HeapStruct* Initialize(int MaxElements)
{
	HeapStruct* H;

	if (MaxElements < MinPQSize)
		Error("Priority queue size is too small!");
	H = malloc(sizeof(HeapStruct));
	if (H == NULL)
		FatalError("Out of space£¡£¡£¡");
	H->Element = malloc((MaxElements + 1) * sizeof(double));

	if (H->Element == NULL)
	{
		FatalError("Out of space!!!");
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Element[0] = MinData;

	return H;
}

void Insert(double X, HeapStruct* H)
{
	int i;

	if (IsFull(H))
	{
		Error("Priority queue is full!");
		return;
	}
	for (i = ++H->Size; H->Element[i / 2] > X; i /= 2)
	{
		H->Element[i] = H->Element[i / 2];
	}
	H->Element[i] = X;	
}

double DeleteMin(HeapStruct* H)
{
	int i, Child;
	double MinElement, LastElement;

	if (IsEmpty(H))
	{
		Error("Priority queue is empty!");
		return H->Element[0];
	}
	MinElement = H->Element[1];
	LastElement = H->Element[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if (Child != H->Size && H->Element[Child = 1] < H->Element[Child])
		{
			Child++;
		}
		if (LastElement > H->Element[Child])
			H->Element[i] = H->Element[Child];
		else
			break;
	}
	H->Element[i] = LastElement;

	return MinElement;
}