#include "optimization.h"
#include <math.h>
#include "activation.h"
//this file has the optimization functions needed in the training process
double derivative_sigmoid(double a)
{
    return sigmoid(a)*(1-sigmoid(a));
}

double derivative_loss(double y,double a)
{
    return (a-y)/(a*(1-a));
}

double derivative_logLoss(double y,double a,double x)
{
    return derivative_loss(y,a) * derivative_sigmoid(a) * x;
}

double vect(double* w,double* x)
{
    double vect = 0;
    for (int i = 0;i<2;i++){
        vect += *(x+i) * *(w+i);
    }
    return vect;
}
