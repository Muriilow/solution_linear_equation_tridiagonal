#ifndef __LINSIS_H__
#define __LINSIS_H__

#include "utils.h"
#include "edo.h"

// Parâmetros default para teste de convergência
#define MAXIT 50
#define TOL  1.0e-4

// Sistema linear Tri-diagonal
typedef struct {
  double *D, *Di, *Ds, *B, *X;
  int n;
} LinearSis;

// Alocaçao e desalocação de matrizes
LinearSis *genLinearSis (Edo *edo);
void freeLinearSis(LinearSis *linSis);

void prnLinearSis(LinearSis *linSis);

// Funções auxiliares
double normaMax(double *X1, double *X0, int n);
double normaL2(double *X, int n);
void residue(LinearSis *SL, double *R, int n);

#endif

