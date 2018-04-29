#include <iostream>
#include <ctime>
#include "loadData.h"
#include "ID3.h"
int main() {
    clock_t t1(clock());

    Instances i;
    DataLoader::ArffReader("/home/squarefong/Documents/PatternRecgnitionPractice/car-evaluation.arff",i);
    ID3 id3(i);
//    vector<int> s;
//    for(int j=0; j<i.size(); ++j){
//        s.push_back(j);
//    }
    id3.setDec(6);
//
//    double a=id3.entropy_Dec(s);
//    cout << id3.entropy_Dec(s) << endl;
//
//    cout << a - id3.entropy(s,"play") << endl;
//
//    cout << a - id3.entropy(s,"outlook") << endl;
//    cout << a - id3.entropy(s,"temperature") << endl;
//    cout << a - id3.entropy(s,"humidity") << endl;
//    cout << a - id3.entropy(s,"windy") << endl;

    id3.startBuildTree();
    id3.showTree();


    clock_t t2(clock());
    std::cout << (t2-t1)/1e6 << std::endl;
    return 0;
}