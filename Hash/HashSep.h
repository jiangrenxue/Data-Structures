#ifndef __HASHSEP_H__
#include <stdio.h>

#define MinTableSize 10
struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTbl* InitializeTable(int TableSize);
void DestroyTable(HashTbl* H);
ListNode* Find(double Key, HashTbl* H);
void Insert(double Key, HashTbl* H);
double Retrieve(ListNode* P);

typedef struct ListNode
{
	double Element;
	ListNode * Next;
}ListNode;

typedef struct HashTbl {
	int TableSize;
	ListNode** TheLists;
}HashTbl;
#endif