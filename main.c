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
#include "free.h"
int main()
{
    //declarations and initiazations
    int i=0;
    char ch[]="dataset.csv",ch1[]="weightsbiasloss.txt";
    double** input;
    char ligne[101];
    double minimum;
    //declaring a 100x3 matrix
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
    //setting learning rate to a medium value (not too precise and not too high)
    double learning_rate=0.1;
    neuron *neuron=NULL;
    neuron=creer_neuronne();
    initialiser_neuronne(neuron);

    //reads csv file and saves it into input(100x3 matrix)
    read_matrix(ch,&input);

    //training network and saving results in the "weightsbiasloss.txt" file
    train_neuron(neuron,learning_rate,100,input);

    //finding the minimum loss and printing the according weights
    min(ch1,&minimum,&ligne);
    printf(" le minimum est :%f\n",minimum);
    affiche_min(ch1,&ligne,minimum);

    //freeing used pointers
    free(ch1);
    free(ch);
    free(input);
    free(neuron->weight);
    free(neuron->next);
    free(neuron->prev);
    free(neuron);
    return 0;
}
