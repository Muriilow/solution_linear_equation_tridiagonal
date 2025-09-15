#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ERRO 1.0e-5
// Valor absoluto de um número real. Alternativa ao uso da função 'fabs()'
#define ABS(num)  ((num) < 0.0 ? -(num) : (num))

// Número máximo de dígitos em um número inteiro
#define numDigits(n)  6  // ( n ? (int) log10(ABS(n)) + 1 : 1 )

// Macro para verificar de valor 'n' é potência de 2 ou não.
// 'n' DEVE ser positivo e não-nulo
#define isPot2(n) (!(n & (n - 1)))     // #define isPot2(n) (n && !(n & (n - 1)))

// Funções
double timestamp(void);
char* markerName(char* baseName, int n);

#endif // __UTILS_H__

