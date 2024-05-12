#ifndef SAVING_H
#define SAVING_H
#define COLS 3
#define LINE 100
void saveWeightBiasLoss(neuron* neuron,double loss);
void read_matrix(char *, double ***);
int trouver(char ch[],char *filename);
int trouver_bias(char ch[],char *filename);
int trouver_weight(char ch[],char *filename);
void afficher(char *filename);
void min(char *filename, double *minimum, char *ligne);
void remp_excel (char *filename ,char *filename1);
#endif
