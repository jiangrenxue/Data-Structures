#ifndef __HASHQUAD_H__
#include <stdio.h>
typedef unsigned int Index;
typedef Index Positon;
#define MinTableSize 10
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitalizeTable(int TableSize);
void DestroyTable(HashTbl* H);
Index Find(double Key, HashTbl*H);

typedef struct HashEntry
{
	double Element;
	enum KindOfEntry Info;
}HashEntry;

typedef struct HashEntry Cell;
typedef struct HashTbl
{
	int TableSize;
	Cell* TheCells;
}HashTbl;
#endif
