#include <stdio.h>
#include "structures.h"
#include "train.h"
#include "Neural_Operations.h"
#include "saving.h"
#include "loss.h"

void train_neuron(neuron *neuron, double learning_rate, int epochs,double **input)
{
    double loss=0,x=0;
    for (int i = 0; i < epochs; i++)
    {
        for(int sample=0;sample<100;sample++)
        {
            x=forward_propagation(neuron,input[sample]);    //calculating the output of the neuron
            loss=loss_function(&x,input[3],1);  //calculating error
            backpropagation(neuron, input[sample],learning_rate);   //updating weights and biases
            saveWeightBiasLoss(neuron,loss);    //saving the weights, bias and loss in the save file
        }
    }
}
