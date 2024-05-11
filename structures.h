#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef struct{
    double output;
    double bias;
    double *weight;
    struct neuron *next;
    struct neuron *prev;
}neuron;

struct layer {
    int num_neurons;
    neuron *neuron;
};
typedef struct layer layer;
#endif
