#ifndef __EQDIFF_H__
#define __EQDIFF_H__

#define FORMAT "%23.15e"
//Murilo de Paula Bob - 20242184
/* Equação Diferencial Ordinária
 * - n: ordem 
 * - a, b: intervalo onde a EDO eh valida
 * - yA, yB: valores de retorno da EDO
 * - p, q: Coeficientes p e q da EDO generica 
 * - r1, r2, r3  e r4: Coeficientes da funcao r(x)
*/
typedef struct {
    int n;
    double a, b;
    double yA, yB; 
    double p, q, r1, r2, r3, r4;
} Edo;

// Print da Edo em formato de sistema linear
void prnEDOsl (Edo *edoeq);

#endif
