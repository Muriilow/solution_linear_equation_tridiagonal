#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <likwid.h>
#include "linearSis.h"
#include "utils.h"
#include "edo.h"

//Murilo de Paula Bob - 20242184
/*
 * SL: Sistema Linear
 * erro: Valor de comparacao para a parada
 * maxit: Valor inteiro para definir o maximo de iteracoes
 * norma: a norma do sistema, ponteiro para retornar o valor  
 * */
int gaussSeidel (LinearSis *SL, double erro, int maxit, double *norma);
