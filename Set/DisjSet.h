#ifndef __DISJSET_H__
#define __DISJSET_H__
#define NumSet 10
typedef int DisjSet[NumSet + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(double X, DisjSet S);

#endif