#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.h"
#include "optimization.h"
#include "Neural_Operations.h"
#include "activation.h"
#include <time.h>


//Forward propagation function generates the output of a neuron
//output is equal to the sum of each weight multiplied by the corresponding input, and then we add the bias of the neuron to the sum and apply the
//sigmoid to the result we obtained
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

//Backward propagation calculates the error and saves the error and the corresponding weights and biases
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

//Function that initializes the weights and biases
void initialiser_neuronne(neuron *neuron)
{

    for (int i = 0; i < 2; i++)
    {
        neuron->weight[i]= (rand()/(double)RAND_MAX) * 2 - 1; //random weightss between -1 and 1
    }
    neuron->bias = (rand()/(double)RAND_MAX) * 2 - 1;//random bias between -1 and 1
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
