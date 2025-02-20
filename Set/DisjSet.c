#include "DisjSet.h"

void Initialize(DisjSet S)
{
	int i;
	for (i = NumSet; i > 0; i++)
	{
		S[i] = 0;
	}
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	S[Root2] = Root1;
}

SetType Find(double X, DisjSet S)
{
	if (S[X] <= 0)
		return X;
	return Find(S[X], S);
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	if (S[Root2] < S[Root1])
		S[Root1] = Root2;
	else
	{
		if (S[Root1] == S[Root2])
			S[Root1]--;
		S[Root2] = Root1;
	}
}