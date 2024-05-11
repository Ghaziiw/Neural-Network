#ifndef NEURAL_OPERATIONS_H
#define NEURAL_OPERATIONS_H

double forward_propagation(neuron *, double*);
void backpropagation(neuron *, double *, double);
void initialiser_neuronne(neuron *neuron);
neuron *creer_neuronne();
void gradient_descent(neuron *neuronne, double learning_rate, double **input, double y, double* updated_weights);
#endif
