//
// Created by squarefong on 18-4-24.
//

#ifndef MACHINELEARNING_ARTIFICIALNEURON_H
#define MACHINELEARNING_ARTIFICIALNEURON_H

#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
//自然常数（Natural constant）
const double e=2.71828182845904523536;

class ArtificialNeuron{
    //权重
    vector<double> weight;
    //阈值
    double threshold;
    double scalarProduct(const vector<double> &x){
        if(x.size()!=weight.size())
        {
            exit(1);
        }
        double result(0.0);
        for(int i=0; i<x.size(); ++i){
            result += x[i] * weight[i];
        }
        return result;
    }
    double activationFunction(double x){
        return 1 / (1 + pow(e,x));
    }
public:
    void setWeight(const vector<double> &Weight){
        weight = Weight;
    }
    bool setWeight(const unsigned &sub, const double &value){
        if (sub >= weight.size())
            return false;
        weight[sub] = value;
        return true;
    }
    void setThreshold(const double &Threshold){
        threshold = Threshold;
    }
    double output(const vector<double> &x){
        double z = scalarProduct(x) + threshold;
        return activationFunction(scalarProduct(x) + threshold);
    }
};


#endif //MACHINELEARNING_ARTIFICIALNEURON_H
