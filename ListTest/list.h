#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef struct Node {
	double value;
	Node* P;
} Node;

Node* MakeEmpty(Node* L);
int IsEmpty(Node* L);
int IsLast(Node *P, Node *L);
Node *Find(double X, Node *L);
void Delete(double X, Node *L);
Node *FindPrevious(double X, Node *L);
void Insert(double X, Node* L, Node *P);
void DeleteList(Node *L);
Node *Hedaer(Node *L);
Node* First(Node *L);
Node* Advance(Node *P);
double Retrieve(Node *P);

#endif