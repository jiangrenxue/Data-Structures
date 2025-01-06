#include "HashSep.h"

HashTbl* InitializeTable(int TableSize)
{
	HashTbl* H;
	int i;

	if (TableSize < MinTableSize)
	{
		Error("Table Size Too Small!");
		return NULL;
	}
	H = malloc(sizeof(HashTbl));
	if (H == NULL)
	{
		FatalError("Out of space!");
	}

	H->TableSize = NextPrime(TableSize);
	H->TheLists = malloc(sizeof(ListNode*) * H->TableSize);

	if (H->TheLists == NULL)
	{
		FatalError("Out Of Space!");
	}

	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = malloc(sizeof(ListNode));
		if (H->TheLists[i] == NULL)
			FatalError("Out Of Space!");
		else
			H->TheLists[i]->Next = NULL;
	}

	return H;
}

ListNode* Find(double Key, HashTbl* H)
{
	ListNode* P;
	ListNode* L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;

	while (P != NULL && P->Element != Key)
	{
		P = P->Next;
	}

	return P;
}

void Insert(double Key, HashTable H)
{
	ListNode* Pos, * NewCell;
	ListNode* L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = malloc(sizeof(ListNode));
		if (NewCell == NULL)
			FatalError("OutOf Space!");
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}
