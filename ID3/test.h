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

//string testFile="/home/squarefong/Documents/PatternRecgnitionPractice/car-evaluation.arff";
string testFile="/opt/weka-3-8-2/data/weather.nominal.arff";

void testID3(){
    clock_t t1(clock());

    Instances i;
    DataLoader::ArffReader(testFile, i);
    ID3 id3(i);

    id3.setDec(4);

    id3.startBuildTree();
    id3.showTree();


    clock_t t2(clock());
    cout << "总计耗时: " << (t2-t1)/1e6 << "ms" << endl;
}
void testC45(){
    clock_t t1(clock());

    Instances i;
    DataLoader::ArffReader(testFile, i);
    C45 c45(i);

    c45.setDec(4);

    c45.startBuildTree();
    c45.showTree();


    clock_t t2(clock());
    cout << "总计耗时: " << (t2-t1)/1e6 << "ms" << endl;
}
#endif //ID3_TEST_H
