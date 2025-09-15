#include  <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "utils.h"
#include "linearSis.h"

LinearSis *genLinearSis (Edo *edo)
{
    LinearSis *SL;
    double x, rx;
    int n = edo->n;

    SL = (LinearSis *) malloc (sizeof(LinearSis));
    SL->n = n;

    SL->D = (double *) calloc(n, sizeof(double));
    SL->Di = (double *) calloc(n, sizeof(double));
    SL->Ds = (double *) calloc(n, sizeof(double));
    SL->B = (double *) calloc(n, sizeof(double));
    SL->X = (double *) calloc(n, sizeof(double));

    double h = (edo->b - edo->a)/(n+1);

    for (int i=0; i < n; ++i) {
        x = edo->a + (i+1)*h;
        rx = edo->r1*x + edo->r2*x*x + edo->r3*cos(x) + edo->r4*exp(x);

        SL->B[i] = h*h * rx;
        SL->Di[i] = 1 - h * edo->p/2.0;
        SL->D[i] = -2 + h*h * edo->q;
        SL->Ds[i] = 1 + h * edo->p/2.0;
    }

    SL->B[0] -= edo->yA * (1 - h*edo->p/2.0);
    SL->B[n-1] -= edo->yB * (1 + h*edo->p/2.0);

    return SL;
}




// Liberacao de memória
void freeLinearSis (LinearSis *SL)
{
    /*
    if (SL) {
        if (SL->A) {
            if (SL->A[0]) free (SL->A[0]);
            free (SL->A);
        }
        if (SL->b) free(SL->b);
        free(SL);
    }
    */
}

void prnLinearSis (LinearSis *SL)
{
}
// Calcula a norma máxima do erro absoluto aproximado de 2 vetores
double normaMax(double *X1, double *X0, int n)
{

    double k, norma = ABS(X1[0] - X0[0]);

    for (int i=1; i < n; ++i)
        if ((k = ABS(X1[i] - X0[i])) > norma)
            norma = k;

    return norma;
}

// Calcula a norma euclidiana de um vetor
double normaL2(double *X, int n)
{

    double norma = 0.0;

    for (int i=0; i < n; ++i)
        norma += X[i]*X[i];

    return sqrt(norma);
}


/* Calcula o resíduo R de um sistema AX = B
   Vetor *R já deve ter sido alocado previamente.
*/
void residue(LinearSis *SL, double *R, int n)
{
    double sum;

    for(int i=0; i < n; ++i) {
        sum = 0.0;

        if(i > 0)
            sum += SL->Di[i] * SL->X[i-1];
        if(i < n-1)
            sum +=  SL->Ds[i] * SL->X[i+1];

        R[i] = SL->B[i] - (sum + SL->D[i]*SL->X[i]);
    }
}

