#include <stdio.h>
#include <stdlib.h>
#include "edo.h"
#include "gaussSeidel.h"
#include "linearSis.h"
#include "utils.h"

int main() 
{
    Edo edo;
    genEdo(&edo);
    double norma;
    int iter;

    LinearSis *linearSis = genLinearSis(&edo);
    iter = gaussSeidel(linearSis, ERRO, 100, &norma);

    printf("\n"); 

    for (int i = 0; i < edo.n; i++)
        printf(FORMAT, linearSis->X[i]);
    printf("\n\n"); 

    printf("%d\n", iter);

    printf(FORMAT, norma);
    printf("\n\n");

    return 0;
}
