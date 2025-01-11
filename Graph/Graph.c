#include "Graph.h"

void Topsort(Graph G)
{
	int Counter;
	Vertex V, W;

	for (Counter = 0; Counter < NumVertex; Counter++)
	{
		V = FindNewVertexOfIndegreeZero();
		if (V == NotAVertex)
		{
			Error("Graph has a cyale!");
			break;
		}
		TopNum[V] = Counter;
		for each W adjacent to v
			Indegree[W]--;
	}	
}

void Topsort(Graph G)
{
	Queue Q;
	int Counter = 0;
	Vertex V, W;

	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	for each vertex V
		if (Indegree[V] == 0)
			Emqueue(V, Q);
	while (!IsEmpty(Q))
	{
		V = Dequeue(Q);
		TopNum[V] = ++Counter;
		for each W adjacent to V
			if (--Indegree[W] == 0)
				Enqueue(W, Q);
	}
	if (Counter != NumVertex)
		Error("Graph has a cycle!");
	DisposeQueue(Q);
}

void Unweighted(Table T)
{
	int CurrDist;
	Vertex V, W;

	for (CurrDist = 0; CurrDist < NumVertex; CurrDist++)
		for each vertex V
			if (!T[V].Known && T[V].Dist == CurrDist)
			{
				T[V].Known = True;
				for each W adjacent to V
					if (T[W].Dsit == Infinity)
					{
						T[W].Dist = CurrDist + 1;
						T[W].Path = V;
					}
			}
}

void Unweighted(Table T)
{
	Queue Q;
	Vertex V, W;

	Enqueue(S, Q);
	while (IsEmpty(Q))
	{
		V = Dequeue(Q);
		T[V].Known = True;
		for each W adjacent to V
			if (T[W].Dist == Infinity)
			{
				T[W].Dist = T[V].Dist + 1;
				T[W].Path = V;
				Enqueue(W, Q);
			}
	}
	DisposeQueue(Q);
}

typedef int Vertex;

typedef struct TableEntry {
	List Header;
	int known;
	DisType Dist;
	Vertex Path;
} TableEntry;

void InitTable(Vertex Start, Graph G, Table T)
{
	int i;
	ReadGraph(G, T);
	for (i = 0; i < NumVertex; i++)
	{
		T[i].Known = False;
		T[i].Dsit = Infinity;
		T[i].Path = NotAVertex;
	}
	T[Start].dist = 0;
}

void PrintPath(Vertex V, Table T)
{
	if (T[V].Path != NotAVertex)
	{
		PrintPath(T[V.Path, T);
		PrintF("to");
	}
	printf("%v", V);
}

void Dijkstra(Table T)
{
	Vertex V, W;
	for (;;)
	{
		V = smallest unknow distance vertex;
		if (V == NotAVertex)
			break;
		T[V].Known = True;
		for each W adjacent to V
			if (!T[W].Known)
				if (T[V].Dist + Cvw < T[W].Dist)
				{
					Decrease(T[W].Dist to T[V].Dist Cvw);
					T[W].Path = V;
				}
	}
}

void WeightdNegative(Table T)
{
	Queue Q;
	Vertex V, W;
	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);

	Enqueue(S, Q);
	while (!IsEmpty(Q))
	{
		V = Dequeue(Q);
		for each W adjacent to V
			if (T[V].Dist + Cvw < T[W].Dist)
			{
				T[W].Dist = T[V].Dist + Cvw;
				T[W].Path = V;
				if (W is not a already in Q)
					Enqueue(W, Q);
			}
	}
	DisposeQueue(Q);
}

void Kruskal(Graph G)
{
	int EdgesAccepted;
	DisjSet S;
	PriorityQueue H;
	Vertex U, V;
	SetType Uset, Vset;
	Edge E;

	Initialize(S);
	ReadGraphIntoHeapArray(G, H);
	BuildHeap(H);
	EdgesAccepted = 0;
	while (EdgesAccepted < NumVertex - 1)
	{
		E = DeleteMin(H);
		Uset = Find(U, S);
		Vset = Find(V, S);
		if (Uset != Vset)
		{
			EdgesAccepted++;
			SetUnion(S, Uset, Vset);
		}
	}
}

void AssignNum(Vertex V)
{
	Vertex W;

	Num[V] = Counter++;
	Visited[V] = True;
	for each W adjacent to V
		if (!Visit[W])
		{
			Parent[W] = V;
			AssignNum(W);
		}
}

void AssignLow(Vertex V)
{
	Vertex W;
	Low[V] = Num[V];
	for each W adjacent to V
	{
		AssignLow(W);
	if (Low[W] >= Num[V])
		printf("%v is an articulation point\n", v);
	Low[V] = Min(Low[V], Num[W]);
	}
}

void FindArt(Vertex V)
{
	Vertex W;
	Visited[V] = True;
	Low[V] = Num[V] = Counter++;
	for each W adjacent to V
	{
		if (!Visited[W])
		{
			Parent[W] = V;
			FindArt(W);
			if (Low[W] >= Num[V])
				printf("%v is an articulation point\n");
			Low[V] = Min(Low[V], Low[W]);
		}
		else if (Parent[V] != W)
			Low[V] = Min(Low[V], Num[W]);
	}

}