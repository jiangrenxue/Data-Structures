#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MinQueueSize (5)

int IsEmpty(QueueRecord *Q);
int IsFull(QueueRecord* Q);
QueueRecord* CreateQueue(int MaxElements);
void DisposeQueue(QueueRecord* Q);
void MakeEmpty(QueueRecord* Q);
void Enqueue(double X, QueueRecord* Q);
double Front(QueueRecord* Q);
void Dequeue(QueueRecord* Q);

typedef struct QueueRecord {
	int Capacity;
	int Front;
	int Rear;
	int Size;
	double* Array;
}QueueRecord;
#endif
