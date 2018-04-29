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
    //计算得到的输出值
    double out;
    //学习速率
    double v;
protected:
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

    double activationFunction(const double &x){
        return 1 / (1 + pow(e,-x));
    }
public:
    ArtificialNeuron():v(0.5),threshold(0.5){

    }
    ArtificialNeuron(const vector<double> &w):v(0.5),weight(w){

    }
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
        out = activationFunction(scalarProduct(x) - threshold);
        return out;
    }

    vector<double> updateWeight(const vector<double> &x, double frac_E_O){
        double w=frac_E_O;
        //w = - target + out;
        w *= out * (1 - out);
        vector<double> frac_E_o;
        for(int i=0; i<weight.size(); ++i){
            frac_E_o.push_back(w*weight[i]);
            weight[i] -= w * x[i] * v;
        }
        return frac_E_o;
    }
};


#endif //MACHINELEARNING_ARTIFICIALNEURON_H
