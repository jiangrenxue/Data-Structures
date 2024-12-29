#ifndef __POLINOMIAL_H__
#define __POLINOMIAL_H__

#include <stdio.h>
#include <math.h>
//#include "List.h"
#define MaxDegree 10

void  ZeroPolynomial(Polynomial* Poly);
void AddPolynomial(const Polynomial* Poly1, const Polynomial* Poly2, Polynomial* PolySum);
void MultPolynomial(const Polynomial* Poly1, const Polynomial* Poly2, Polynomial* PolyProd);
typedef struct {
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} Polynomial;

typedef struct Node{
	int Coefficient;
	int Exponent;

	Node* Next;
} Node;
#endif

