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
protected:
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

    string judge(const Instance &rhs){
        node *current=tr;
        while (true) {
            string attrName = current->attribution;
            int attrSub = dataSets.getAttributionsSub(attrName);
            auto f = current->kids.find(rhs[attrSub]);
            if(f != current->kids.end()){
                current = (*f).second;
                if(current->kids.size() == 0)
                    return current->attribution;
            } else{
                return "";
            }
        }
    }

    void test(const Instances & rhs){
        double correctCounter=0.0;
        double errorCounter=0.0;
        double nullCounter=0.0;
        for(int i=0; i<rhs.size(); ++i) {
            auto tempIns = rhs[i];
            string result = judge(rhs[i]);
            if (result == "")
                ++nullCounter;
            else if (result == rhs[i][decAttribution]) {
                ++correctCounter;
            } else
                ++errorCounter;
        }
        cout << "测试实例总共" << rhs.size() << "个测试样本，其中：\n";
        cout << "正确分类的有：" << correctCounter << "个测试样本，正确率：" << correctCounter/rhs.size() << endl;
        cout << "错误分类的有：" << errorCounter << "个测试样本，错误率：" << errorCounter/rhs.size() << endl;
        cout << "拒绝分类的有：" << nullCounter << "个测试样本，拒绝率：" << nullCounter/rhs.size() << endl;

    }
};


#endif //ID3_ID3_H
