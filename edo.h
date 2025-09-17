#ifndef __EQDIFF_H__
#define __EQDIFF_H__

#define FORMAT "%23.15e"

// Equação Diferencial Ordinária
typedef struct {
    int n; // número de pontos internos na malha
    double a, b; // intervalo
    double yA, yB; // condições contorno
    double p, q, r1, r2, r3, r4; // coeficientes EDO genérica
} Edo;

// Funções auxiliares
void prnEDOsl (Edo *edoeq);

#endif // __EQDIFF_H__
