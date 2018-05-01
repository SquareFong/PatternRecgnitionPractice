#include <iostream>
#include "loadData.h"
#include "NaiveBayes.h"

void test(NaiveBayes & nb, Instances &ins){
    int dec = nb.getDecisionAttribution();
    double accuracy = 0.0;
    vector<string> test(ins.attributionSize(), "");
    for(int i = 0; i < ins.size(); ++i){
        auto temp = ins[i];
        for(int j = 0; j < ins.attributionSize(); ++j){
            if(j == dec)
                continue;
            test[j] = temp[j];
            cout << test[j] << ',';
        }
        cout << temp[dec] << " ";
        if(nb.judge(test) == temp[dec]){
            accuracy += 1;
            cout << 'V' << endl;
        } else{
            cout << 'X' << endl;
        }
    }
    cout << "total accuracy: " << accuracy / ins.size();
}

int main() {
    Instances i;
    DataLoader::ArffReader("../../testDatas/weather.nominal_with_interference.arff",i);
    //cout << i;

    NaiveBayes nb(i);
    nb.setDec(4);
    std::cout << "Hello, World!" << std::endl;
    nb.buildNBTree();

//    vector<string> test;
//    test.push_back("sunny");
//    test.push_back("hot");
//    test.push_back("high");
//    test.push_back("FALSE");
//    test.push_back("");
//    cout << nb.judge(test) << endl;

    test(nb, i);
    return 0;
}
