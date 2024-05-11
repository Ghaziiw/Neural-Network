#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "activation.h"
#include "structures.h"
#include "Neural_Operations.h"
#include "train.h"
#include "optimization.h"
#include "loss.h"
#include "saving.h"
int main()
{
    int i=0;
    char ch[]="C:/Neural Network/dataset.csv";
    double** input;
    char ligne[101];
    double minimum;
    char *ch1="C:/Neural Network/weightsbiasloss.txt";
    input=(double**)malloc(100*sizeof(double*));
    if (input == NULL) {
        printf("Memory allocation failed");
        return 0;
    }
    for(i=0;i<100;i++)
    {
        input[i]=(double*)malloc(3*sizeof(double));
        if (input[i] == NULL)
        {
        printf("Memory allocation failed");
        return 0;
        }
    }
    double learning_rate=0.1;
    neuron *neuron=NULL;
    neuron=creer_neuronne();
    initialiser_neuronne(neuron);

    read_matrix(ch,&input);
    train_neuron(neuron,learning_rate,100,input);
    min(ch1,&minimum,&ligne);
    printf(" le minimum est :%f\n",minimum);
    affiche_min(ch1,&ligne,minimum);

    return 0;

}
