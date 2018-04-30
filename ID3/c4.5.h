//
// Created by squarefong on 18-4-30.
//

#ifndef ID3_C4_5_H
#define ID3_C4_5_H

#include "ID3.h"

class C45 : public ID3{
public:
    C45(const string&filePath):ID3(filePath){}
    C45(const Instances & rhs):ID3(rhs){

    }
    void startBuildTree(){
        vector<int> s;
        for(int j=0; j<dataSets.size(); ++j){
            s.push_back(j);
        }
        bool used[dataSets.attributionSize()]={false};
        tr = new node();
        buildC45Tree(s,used,tr);
    }
    void buildC45Tree(const vector<int> &sub, bool *usedAttribution, node * branch){
        //决策属性的熵
        double decEntropy=this->entropy_Dec(sub);
        if(decEntropy*decEntropy < 0.00000000001) {
            branch->attribution = dataSets[sub[0]][decAttribution];
            return;
        }
        //各个属性的增益率
        map<string,double> ents;
        for(int i = 0; i < dataSets.attributionSize(); ++i){
            if(i != decAttribution && !usedAttribution[i]){
                string attributionName=dataSets.getAttributionName(i);
                double ent=entropy(sub,i);
                double inf=info(sub,i);
                ents.insert(make_pair(attributionName, (decEntropy-ent)/inf));
            }
        }
        if(ents.size() == 0)
            return;
        //挑出熵增最大的属性
        auto it=ents.begin();
        for(auto i=ents.begin(); i != ents.end(); ++i){
            if((*i).second > (*it).second)
                it=i;
        }
        int maxEntropySub=dataSets.getAttributionsSub((*it).first);
        usedAttribution[maxEntropySub] = true;
        //构造结点
        branch->attribution=((*it).first);
        set<string> decision=dataSets.getAttributions((*it).first);
        for(auto i=decision.begin(); i != decision.end(); ++i){
            if((*it).second*(*it).second < 0.0000000001)
                branch->kids.insert(make_pair((*i), nullptr));
            else
                branch->kids.insert(make_pair((*i), new node()));
        }

        //熵减为零，结束
        if((*it).second*(*it).second < 0.0000000001){
            ;
        } else{
            for(auto treeIt=branch->kids.begin(); treeIt!=branch->kids.end(); ++treeIt) {
                vector<int> nextSub;
                for (auto i = sub.begin(); i != sub.end(); ++i) {
                    if (dataSets[(*i)][maxEntropySub] == (*treeIt).first)
                    {
                        nextSub.push_back((*i));
                    }
                }
                buildID3Tree(nextSub, usedAttribution, (*treeIt).second);
            }
        }
        usedAttribution[maxEntropySub] = false;
    }
};

#endif //ID3_C4_5_H
