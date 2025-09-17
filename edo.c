#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "utils.h"
#include "edo.h"

// Exibe SL na saída padrão
void prnEDOsl (Edo *edoeq)
{
    int n = edoeq->n, i, j;
    double x, b, d, di, ds,rx;
    double h = (edoeq->b - edoeq->a)/(n+1);

    printf ("%d\n", n);

    for (i=0; i < n; ++i) {
        x = edoeq->a + (i+1)*h;
        rx = edoeq->r1*x + edoeq->r2*x*x + edoeq->r3*cos(x) + edoeq->r4*exp(x);

        b = h*h * rx; 
        di = 1 - h * edoeq->p/2.0;
        d = -2 + h*h * edoeq->q;
        ds = 1 + h * edoeq->p/2.0;

        for (j=0; j < n; ++j) {
            if (i == j)
                printf (FORMAT,d);
            else if (j == i-1 && i)
                printf (FORMAT,di);
            else if (j == i+1 && i != n-1)
                printf (FORMAT,ds);
            else
                printf(FORMAT, 0.0);
        }

        if (i == 0)
            b -= edoeq->yA * (1 - h*edoeq->p/2.0);
        else if (i == n-1)
            b -= edoeq->yB * (1 + h*edoeq->p/2.0);

        printf (FORMAT, b);

        printf ("\n");
    }
}
