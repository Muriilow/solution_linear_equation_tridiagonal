#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linearSis.h"
#include "utils.h"
#include "edo.h"

int gaussSeidel (LinearSis *SL, double erro, int maxit, double *norma);
