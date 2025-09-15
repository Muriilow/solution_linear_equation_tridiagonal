#include <stdlib.h>
#include "gaussSeidel.h"

// Método de Gauss-Seidel clássico
int gaussSeidel (LinearSis *SL, double erro, int maxit, double *norma)
{
    int n = SL->n;
    int it = 0;
    double sum = 0.0; 
    double newError = 0.0;
    double res[n];

    do {
        newError = 0.0;
        for (int i = 0; i < n; i++) 
        {
            sum = 0.0;
            if(i > 0)
                sum += SL->Di[i] * SL->X[i-1];
            if(i < n-1)
                sum +=  SL->Ds[i] * SL->X[i+1];

            SL->X[i] = (SL->B[i] - sum) / SL->D[i];
        }

        residue(SL, res, n);
        *norma = normaL2(res, n);
        it++;
    } while (it < maxit && *norma > erro);
   
    return it;
}
