#ifndef __BINHEAP_H__
#define __BINHEAP_H__
#include <stdio.h>

#define MinPQSize 10
#define MinData 0

HeapStruct* Initialize(int MaxElenets);
void Destroy(HeapStruct* H);
void MakeEmpty(HeapStruct *H);
void Insert(HeapStruct *X, HeapStruct* H);
double DeleteMin(HeapStruct* H);
double FindMin(HeapStruct* H);
int IsEmpty(HeapStruct* H);
int IsFull(HeapStruct* H);

typedef struct HeapStruct
{
	int Capacity;
	int Size;
	double* Element;
}HeapStruct;
#endif
