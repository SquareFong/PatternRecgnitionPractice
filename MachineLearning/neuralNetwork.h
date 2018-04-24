//
// Created by squarefong on 18-4-18.
//

#ifndef MACHINELEARNING_NEURALNETWORK_H
#define MACHINELEARNING_NEURALNETWORK_H

#include "artificialNeuron.h"

class neuronLayer{
    vector<ArtificialNeuron> layer;
public:
    void push(const ArtificialNeuron& a){
        layer.push_back(a);
    }
};

class BPNeuronNetwork{
    vector<neuronLayer> bp;
public:
    void push(const neuronLayer& l){
        bp.push_back(l);
    }
};

#endif //MACHINELEARNING_NEURALNETWORK_H
