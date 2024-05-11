#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.h"
#include "optimization.h"
#include "Neural_Operations.h"
#include "activation.h"
#include <time.h>
//Fonction qui génere un output de la neuronne d'entrée en fonction des output des neuronnes de la couche précédente
double  forward_propagation(neuron *neuron,double *input)
{
    int i=0;
    double output=0;
    for(i=0;i<2;i++)
    {
        output=output+(neuron->weight[i])*input[i];
    }
    neuron->bias = (rand() / (double)RAND_MAX) * 2 - 1;
    return sigmoid(output);

}

//Fonction backward propagation
void backpropagation(neuron *neuron, double *input,double learning_rate)
{
    double output = forward_propagation(neuron, input);
    double error = input[3] - output;
    neuron->bias += learning_rate * error * derivative_sigmoid(neuron->bias);

    for (int i = 0; i < 2; i++)
    {
        neuron->weight[i] += learning_rate * error * derivative_sigmoid(neuron->weight[i]) * input[i];
    }
}

//Fonction qui initialise le bias et weight à une valeur aléatoire entre -1 et 1
void initialiser_neuronne(neuron *neuron)
{
    for (int i = 0; i < 2; i++)
    {
        neuron->weight[i]= 1;
    }
    neuron->bias = (rand()/(double)RAND_MAX) * 2 - 1;
    neuron->output = 0;
}

//Fonction qui crée une neuronne
neuron *creer_neuronne()
{
    neuron *neur=NULL;
    neur=(neuron *)malloc(sizeof(neuron));
    if (neur==NULL)
    {
        printf("erreur d'allocation !");
        return NULL;
    }
    neur->weight=(double*)malloc(2*sizeof(double));
    if (neur->weight==NULL)
    {
        printf("erreur d'allocation !");
        return NULL;
    }
    return neur;
}


//Fonction de descente de Gradient
/*void gradient_descent(neuron *neuronne, double learning_rate, double input[2], double y, double* updated_weights) {

    for (int i = 0; i < 2; i++) {
        updated_weights[i] = neuronne->weights[i] + learning_rate * derivative_logLoss(y, neuronne->output, input[i]);
    }
}*/
