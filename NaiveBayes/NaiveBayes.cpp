//
// Created by squarefong on 18-4-14.
//

#include "NaiveBayes.h"

bool NaiveBayes::setDec(unsigned n){
    if(n < dataSets.attributionSize())
    {
        decAttribution = n;
        return true;
    }
    return false;
}

void NaiveBayes::buildNBTree(){
    nbClass = NBClass(dataSets, decAttribution);
    map<string, double> decCounter;
    set<string> decisionAttribution=dataSets.getAttributions(decAttribution);
    for(auto i=decisionAttribution.begin(); i!= decisionAttribution.end(); ++i){
        decCounter.insert(make_pair((*i),0.0));
    }

    for(int i = 0; i<dataSets.size(); ++i){
        Instance temp = dataSets[i];
        decCounter[temp[decAttribution]] += 1;
        for(int j(0); j < dataSets.attributionSize(); ++j){
//                if(j == decAttribution)
//                    continue;
            nbClass[dataSets.getAttributionName(j) + "=" + temp[j]][temp[decAttribution]] += 1;
        }
    }
    decisionAttributionCounter = decCounter;
    //cout << "yes:" << decCounter["yes"] << ' ' << "no" << decCounter["no"] << endl;

    for(auto it=nbClass.decisionAttributes.begin(); it != nbClass.decisionAttributes.end(); ++it){
        map<string, int> &cat = (*it).second;
        for(auto it2 = cat.begin(); it2 != cat.end(); ++it2) {
            auto temp = nbClass.attributions[(*it2).second];
            for(auto it3 = decCounter.begin(); it3 != decCounter.end(); ++it3){
                nbClass[(*it).first + "=" + (*it2).first][(*it3).first] /= (*it3).second;
            }
        }

    }
    cout << nbClass;
}

string NaiveBayes::judge(const vector<string> &rhs){
    vector<string> a;
    for(int i = 0; i < dataSets.attributionSize(); ++i){
        if(i == decAttribution)
            continue;
        a.push_back(dataSets.getAttributionName(i)+"="+rhs[i]);
    }
    map<string, double> result=decisionAttributionCounter;
    for(auto i = result.begin(); i!= result.end(); ++i){
        (*i).second /= dataSets.size();
        for(auto j=a.begin(); j!=a.end(); ++j){
            (*i).second *= nbClass[*j][(*i).first];
        }
    }
    auto it=result.begin();
    for(auto i = result.begin(); i != result.end(); ++i){
        if((*i).second > (*it).second){
            it = i;
        }
    }
    return (*it).first;
}