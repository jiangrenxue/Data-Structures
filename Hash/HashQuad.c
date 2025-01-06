#include "HashQuad.h"

HashTbl* InitializeTable(int TableSize)
{
	HashTbl* H;
	int i;

	if (TableSize < MinTableSize)
	{
		Error("Table size too small");
		return NULL;
	}
	H = malloc(sizeof(HashTbl));
	if (H == NULL)
		FatalError("Out of space!");
	H->TableSize = NextPrime(TableSize);
	H->TheCells = malloc(sizeof(HashEntry) * H->TableSize);
	if (H->TheCells == NULL)
		FatalError("Out of space!");
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheCells[i].Info = NULL;
	}
	return H;
}

Index Find(double Key, HashTbl* H)
{
	Index CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != NULL &&
		H->TheCells[CurrentPos].Element != Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}

	return CurrentPos;
}

void Insert(double Key, HashTbl* H)
{
	Index Pos;

	Pos = Find(Key, H);
	If(H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}

HashTbl* Rehash(HashTbl* H)
{
	int i, OldSize;
	Cell* OldCells;
	OldCells = H->TheCells;
	OldSize = H->TableSize;
	H = InitalzieTable(2*OldSize);

	for (i = 0; i < OldSize; i++)
	{
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);
		free(OldCells);
	}

	return H;
}