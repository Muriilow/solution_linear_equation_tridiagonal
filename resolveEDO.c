#include <stdio.h>
#include <stdlib.h>
#include "edo.h"
#include "gaussSeidel.h"
#include "linearSis.h"
#include "utils.h"

int main() 
{
    Edo edo;
    double norma;
    int iter;



    int result; 
    scanf("%d", &edo.n); 
    scanf("%lf %lf", &edo.a, &edo.b);
    scanf("%lf %lf", &edo.yA, &edo.yB);
    scanf("%lf %lf", &edo.p, &edo.q);

    result = scanf("%lf %lf %lf %lf", &edo.r1, &edo.r2, &edo.r3, &edo.r4);

    do 
    {
        prnEDOsl(&edo);
        LinearSis *linearSis = genLinearSis(&edo);
        iter = gaussSeidel(linearSis, ERRO, 100, &norma);

        printf("\n"); 

        for (int i = 0; i < edo.n; i++)
            printf(FORMAT, linearSis->X[i]);
        printf("\n\n"); 

        printf("%d\n", iter);

        printf(FORMAT, norma);
        printf("\n\n");
    }
    while(scanf("%lf %lf %lf %lf", &edo.r1, &edo.r2, &edo.r3, &edo.r4) == 4);

    return 0;
}
