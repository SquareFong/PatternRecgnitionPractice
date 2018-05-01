//
// Created by squarefong on 18-4-30.
//

#ifndef ID3_TEST_H
#define ID3_TEST_H
#include <iostream>
#include <ctime>
#include "loadData.h"
#include "ID3.h"
#include "c4.5.h"
using namespace std;

string testFile="../../testDatas/weather.nominal_with_interference.arff";
//string testFile="/opt/weka-3-8-2/data/weather.nominal.arff";
double rate=0.8;
void testID3(){
    cout << "ID3" << endl;
    Instances i;
    DataLoader::ArffReader(testFile, i);

    Instances trainingSet;
    Instances testSet;
    DataLoader::spliteInstace(i,trainingSet,testSet, rate);

    clock_t t1(clock());
    ID3 id3(trainingSet);

    id3.setDec(5);

    id3.startBuildTree();
    id3.showTree();


    clock_t t2(clock());
    cout << "总计耗时: " << (t2-t1)/1e6 << "ms" << endl;
    id3.test(testSet);
    cout << endl;
}
void testC45(){
    cout << "C4.5" << endl;

    Instances i;
    DataLoader::ArffReader(testFile, i);


    Instances trainingSet;
    Instances testSet;
    DataLoader::spliteInstace(i,trainingSet,testSet, rate);

    clock_t t1(clock());
    C45 c45(trainingSet);

    c45.setDec(5);

    c45.startBuildTree();
    c45.showTree();


    clock_t t2(clock());
    cout << "总计耗时: " << (t2-t1)/1e6 << "ms" << endl;
    c45.test(testSet);
    cout << endl;
}
#endif //ID3_TEST_H
