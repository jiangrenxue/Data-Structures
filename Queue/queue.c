#include "queue.h"

int IsEmpty(QueueRecord* Q)
{
	return Q->Size == 0;
}

void MakeEmpty(QueueRecord* Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int value, QueueRecord* Q)
{
	if (IdFull(Q))
	{
		Error("Full queue!");
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}