//
// Created by squarefong on 18-4-18.
//

#ifndef MACHINELEARNING_NEURALNETWORK_H
#define MACHINELEARNING_NEURALNETWORK_H

#include "artificialNeuron.h"

class neuronLayer{
public:
    vector<ArtificialNeuron> layer;
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
    void train(const vector<double> &x, const vector<double> &target){
        vector<vector<double>> outs;
        vector<double > output = x;
        for(auto &layer : bp){
            vector<double> tempOut;
            for(auto &n : layer.layer){
                tempOut.push_back(n.output(output));
            }
            outs.push_back(tempOut);
            output = tempOut;
        }
        vector<double> tar = target;
        for(int i=0; i<tar.size(); ++i){
            tar[i] = outs[outs.size()-1][i] - tar[i];
        }

        for(int i=(int)(outs.size()-1); i >= 0; --i){
            auto &layer=bp[i].layer;
            vector<double> frac_E_o(layer[0].updateWeight(outs[i],tar[0]));
            for(int j(1); j < layer.size(); ++j){
                auto tempFrac = layer[j].updateWeight(outs[i],tar[j]);
                for(int n=0; n < frac_E_o.size(); ++n){
                    frac_E_o[n] += tempFrac[n];
                }
            }
            tar = frac_E_o;
        }
    }

    vector<double> test(const vector<double> &x){
        vector<double > output = x;
        for(auto &layer : bp){
            vector<double> tempOut;
            for(auto &n : layer.layer){
                tempOut.push_back(n.output(output));
            }
            output = tempOut;
        }
    }
};

#endif //MACHINELEARNING_NEURALNETWORK_H
