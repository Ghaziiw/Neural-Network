#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "activation.h"

double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}
