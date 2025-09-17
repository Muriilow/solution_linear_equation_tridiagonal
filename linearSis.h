#ifndef __LINSIS_H__
#define __LINSIS_H__

#include "utils.h"
#include "edo.h"
//Murilo de Paula Bob - 20242184

/* Sistema linear Tri-diagonal
 * D: Vetor da diagonal principal
 * D: Vetor da diagonal abaixo da principal
 * D: Vetor da diagonal acima da principal
 * B: Vetor dos valores independentes
 * X: Vetor dos resultados do sistema
 * n: Ordem do Sitema Linear
*/
typedef struct {
  double *D, *Di, *Ds, *B, *X;
  int n;
} LinearSis;

//Gera o sistema linear com base na Edo
LinearSis *genLinearSis (Edo *edo);

//Libera a memoria alocada do sistema linear
void freeLinearSis(LinearSis *linSis);

/* Calcula a norma 
 * X: Vetor para calcular a norma, geralmente o vetor X do SL
 * n: Ordem do sistema linear
*/
double normaL2(double *X, int n);

/* Calcula o residuo de um sistema linear
 * SL: O sistema linear a ser calculado 
 * R: Vetor do residuo para retorno
 * n: Ordem do sistema linear
 * */
void residue(LinearSis *SL, double *R, int n);

#endif

