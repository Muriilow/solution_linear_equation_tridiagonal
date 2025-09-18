#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Murilo de Paula Bob - 20242184

#define ERRO 1.0e-5
// Valor absoluto de um número real. Alternativa ao uso da função 'fabs()'
#define ABS(num)  ((num) < 0.0 ? -(num) : (num))

// Funções
double timestamp(void);

#endif // __UTILS_H__

