//
// Created by squarefong on 18-4-1.
//

#ifndef ID3_ID3_H
#define ID3_ID3_H

#include "loadData.h"
#include <map>
#include <cmath>
using namespace std;
class ID3 {
    Instances dataSets;
    vector<string> ID3tree;
    int decAttribution;
    struct node{
        string attribution;
        map<string, node*> kids;
        node(){

        }
    };
    node *tr;
public:
    ID3(const string&filePath):decAttribution(0){
        DataLoader::ArffReader(filePath,dataSets);
    }

    ID3(const Instances & rhs):decAttribution(0){
        dataSets=rhs;
    }

    bool setDec(unsigned n);

    //传入下标, 和属性名称以计算信息熵
    double entropy(const vector<int> &sub, const string &attributionName);

    double entropy_Dec(const vector<int> &sub);

    double entropy(const vector<int> &sub, const int &attributionSub);

    void startBuildTree();

    void buildID3Tree(const vector<int> &sub, bool *usedAttribution, node * branch);

    void showTree(node * id3tree= nullptr, const string&control="");
};


#endif //ID3_ID3_H
