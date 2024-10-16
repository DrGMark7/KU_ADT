#include <stdio.h>
#include <stdlib.h>
#include <ranlib.h>

typedef struct Node{
    double bias;
    double *weights;
}Node;

typedef struct Layer{
    int numNodes;
    Node *nodes;
}Layer;

typedef struct NeuralNetwork{
    int numLayers;
    Layer *layers;
}NeuralNetwork;

NeuralNetwork *createNeuralNetwork(int numLayers, int *numNodes){
    NeuralNetwork *nn = (NeuralNetwork *)malloc(sizeof(NeuralNetwork));
    nn->numLayers = numLayers;
    nn->layers = (Layer *)malloc(numLayers * sizeof(Layer));
    for(int i = 0; i < numLayers; i++){
        nn->layers[i].numNodes = numNodes[i];
        nn->layers[i].nodes = (Node *)malloc(numNodes[i] * sizeof(Node));
        for(int j = 0; j < numNodes[i]; j++){
            nn->layers[i].nodes[j].weights = (double *)malloc(numNodes[i] * sizeof(double));
            for(int k = 0; k < numNodes[i]; k++){
                nn->layers[i].nodes[j].weights[k] = (double)rand()/RAND_MAX;
            }
            nn->layers[i].nodes[j].bias = (double)rand()/RAND_MAX;
        }
    }
    return nn;
}

void printNeuralNetwork(NeuralNetwork *nn){
    for(int i = 0; i < nn->numLayers; i++){
        printf("Layer %d\n", i);
        for(int j = 0; j < nn->layers[i].numNodes; j++){
            printf("Node %d\n", j);
            printf("Bias: %f\n", nn->layers[i].nodes[j].bias);
            for(int k = 0; k < nn->layers[i].numNodes; k++){
                printf("Weight %d: %f\n", k, nn->layers[i].nodes[j].weights[k]);
            }
        }
        printf("\n");
    }

}

void freeNeuralNetwork(NeuralNetwork *nn){
    for(int i = 0; i < nn->numLayers; i++){
        for(int j = 0; j < nn->layers[i].numNodes; j++){
            free(nn->layers[i].nodes[j].weights);
        }
        free(nn->layers[i].nodes);
    }
    free(nn->layers);
    free(nn);
}

double *GenarateRandomArray(int n){
    double *arr = (double *)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        arr[i] = rand();
    }
    return arr;
}

double *feedForward(NeuralNetwork *nn){
    double *output = (double *)malloc(nn->layers[nn->numLayers-1].numNodes * sizeof(double));
    for(int i = 0; i < nn->layers[0].numNodes; i++){
        output[i] = 0;
        for(int j = 0; j < nn->layers[0].numNodes; j++){
            output[i] += nn->layers[0].nodes[j].weights[i] * nn->layers[0].nodes[j].bias;
        }
    }
    return output;
}

double lossFunction(double *output, double *target, int n){
    double loss = 0;
    for(int i = 0; i < n; i++){
        loss += (output[i] - target[i]) * (output[i] - target[i]);
    }
    return loss;
}

double *backPropagation(NeuralNetwork *nn, double *output, double *target){
    double *delta = (double *)malloc(nn->layers[nn->numLayers-1].numNodes * sizeof(double));
    for(int i = 0; i < nn->layers[nn->numLayers-1].numNodes; i++){
        delta[i] = 2 * (output[i] - target[i]);
    }
    return delta;
}

void updateWeights(NeuralNetwork *nn, double *delta){
    for(int i = 0; i < nn->layers[0].numNodes; i++){
        for(int j = 0; j < nn->layers[0].numNodes; j++){
            nn->layers[0].nodes[j].weights[i] -= 0.01 * delta[i] * nn->layers[0].nodes[j].bias;
        }
    }
}

void train(NeuralNetwork *nn, double *input, double *target){
    double *output = feedForward(nn);
    double loss = lossFunction(output, target, nn->layers[nn->numLayers-1].numNodes);
    double *delta = backPropagation(nn, output, target);
    updateWeights(nn, delta);
}

int *predict(NeuralNetwork *nn, double *input){
    double *output = feedForward(nn);
    int *prediction = (int *)malloc(nn->layers[nn->numLayers-1].numNodes * sizeof(int));
    for(int i = 0; i < nn->layers[nn->numLayers-1].numNodes; i++){
        prediction[i] = output[i] > 0.5 ? 1 : 0;
    }
    return prediction;
}

int main(){
    int numLayers = 3;
    int numNodes[] = {2, 2, 2};
    NeuralNetwork *nn = createNeuralNetwork(numLayers, numNodes);
    printNeuralNetwork(nn);

    double *input = GenarateRandomArray(numNodes[0]);
    
    double *output = feedForward(nn);
    for(int i = 0; i < numNodes[numLayers-1]; i++){
        printf("%lf ", output[i]);
    }
    printf("\n");

    double target[] = {1, 0};

    int iter;
    printf("Enter number of iterations: ");
    scanf("%d", &iter);
    for (int i = 0; i < iter; i++){
        train(nn, input, target);
    }
    printf("After training\n");
    printNeuralNetwork(nn);

    output = feedForward(nn);
    printf("\n");
    for(int i = 0; i < numNodes[numLayers-1]; i++){
        printf("%lf ", output[i]);
    }
    
    int *prediction = predict(nn, input);
    printf("Prediction: %d\n", prediction[0]);

    return 0;
}