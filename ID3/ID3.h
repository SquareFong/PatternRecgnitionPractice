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
public:
    ID3(const string&filePath):decAttribution(0){
        DataLoader::ArffReader(filePath,dataSets);
    }
    ID3(const Instances & rhs):decAttribution(0){
        dataSets=rhs;
    }
    bool setDec(unsigned n){
        if(n < dataSets.attributionSize())
        {
            decAttribution = n;
            return true;
        }
        return false;
    }

    //传入下标, 和属性名称以计算信息熵
    double entropy(vector<int> sub, const string &attributionName){
        double ent=0.0;
        set<string> decision=dataSets.getAttributions(decAttribution);
        map<string,double> possibilities;
        for(auto i=decision.begin(); i != decision.end(); ++i){
            possibilities.insert(make_pair((*i),0));
        }
        int attributionSub=dataSets.getAttributionsSub(attributionName);
        for(int i=0; i<sub.size(); ++i){
            const string &value=dataSets[sub[i]][attributionSub];
            possibilities[value] += 1;
        }
        for(auto i=possibilities.begin(); i != possibilities.end(); ++i){
            (*i).second /= sub.size();
            ent += -(*i).second*log2((*i).second);
        }
        return ent;
    }

    void buildID3Tree(){
        vector<int> sub;
        for(int j=0; j<dataSets.size(); ++j){
            sub.push_back(j);
        }
        double ent=this->entropy(sub,"play");
    }
};


#endif //ID3_ID3_H
