#include <stdio.h>
#include <likwid.h>
#include "edo.h"
#include "gaussSeidel.h"
#include "linearSis.h"
#include "utils.h"

#define FORMAT_SHORT "%16.8e"

int main() 
{
    LIKWID_MARKER_INIT;
    Edo edo;
    double norma;
    int iter;
    int result; 
    int i = 0;
    //Registrando informações da edo 
    scanf("%d", &edo.n); 
    scanf("%lf %lf", &edo.a, &edo.b);
    scanf("%lf %lf", &edo.yA, &edo.yB);
    scanf("%lf %lf", &edo.p, &edo.q);

    //Registrando valores r1, r2, r3, e r4 de r(x)
    result = scanf("%lf %lf %lf %lf", &edo.r1, &edo.r2, &edo.r3, &edo.r4);

    //O laço continuará caso o usuário coloque múltiplos valores de r(x)
    do 
    {
        prnEDOsl(&edo);

        LinearSis *linearSis = genLinearSis(&edo);
        double time = timestamp();
        char region_name[50];
        snprintf(region_name, sizeof(region_name), "GAUSS_SEIDEL_%d", i);
        LIKWID_MARKER_START(region_name);
        iter = gaussSeidel(linearSis, ERRO, 100, &norma);
        LIKWID_MARKER_STOP(region_name);

        printf("\n"); 

        for (int i = 0; i < edo.n; i++)
            printf(FORMAT, linearSis->X[i]);
        printf("\n\n"); 

        printf("%d\n", iter);
        printf(FORMAT, time);
        printf(FORMAT_SHORT, norma);
        printf("\n\n");
        i++;
        time = timestamp() - time;
    }
    while(scanf("%lf %lf %lf %lf", &edo.r1, &edo.r2, &edo.r3, &edo.r4) == 4);

    LIKWID_MARKER_CLOSE;
    return 0;
}
