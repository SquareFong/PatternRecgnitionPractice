//
// Created by squarefong on 18-4-1.
//

#include "ID3.h"

bool ID3::setDec(unsigned n){
    if(n < dataSets.attributionSize())
    {
        decAttribution = n;
        return true;
    }
    return false;
}

double ID3::entropy(const vector<int> &sub, const string &attributionName){
    int attributionSub=dataSets.getAttributionsSub(attributionName);
    return entropy(sub, attributionSub);
}

double ID3::entropy(const vector<int> &sub, const int &attributionSub){
    double ent=0.0;
    set<string> decision=dataSets.getAttributions(attributionSub);
    map<string,vector<int>> possibilities;
    for(auto i=decision.begin(); i != decision.end(); ++i){
        possibilities.insert(make_pair((*i),vector<int>()));
    }
    for(int i=0; i<sub.size(); ++i){
        const string &value=dataSets[sub[i]][attributionSub];
        possibilities[value].push_back(sub[i]);
    }
    for(auto i=possibilities.begin(); i != possibilities.end(); ++i){
        double temp=entropy_Dec((*i).second);
        ent += ((double)(*i).second.size())*temp/(double)sub.size();
    }
    return ent;

}

double ID3::entropy_Dec(const vector<int> &sub){
    double ent=0.0;
    set<string> decision=dataSets.getAttributions(decAttribution);
    map<string,int> possibilities;
    for(auto i=decision.begin(); i != decision.end(); ++i){
        possibilities.insert(make_pair((*i),0));
    }
    for(int i=0; i<sub.size(); ++i){
        const string &value=dataSets[sub[i]][decAttribution];
        ++possibilities[value];
    }
    for(auto i=possibilities.begin(); i != possibilities.end(); ++i){
        double t=(*i).second/(double)sub.size();
        if(t*t < 0.0000001)
            continue;
        ent += -t*log2(t);
    }
    return ent;
}

void ID3::startBuildTree(){
    vector<int> s;
    for(int j=0; j<dataSets.size(); ++j){
        s.push_back(j);
    }
    bool used[dataSets.attributionSize()]={false};
    tr = new node();
    buildID3Tree(s,used,tr);
}

void ID3::buildID3Tree(const vector<int> &sub, bool *usedAttribution, node * branch){
    //决策属性的熵
    double decEntropy=this->entropy_Dec(sub);
    if(decEntropy*decEntropy < 0.00000000001) {
        branch->attribution = dataSets[sub[0]][decAttribution];
        return;
    }
    //各个属性的熵
    map<string,double> ents;
    for(int i = 0; i < dataSets.attributionSize(); ++i){
        if(i != decAttribution && !usedAttribution[i]){
            string attributionName=dataSets.getAttributionName(i);
            double ent=entropy(sub,i);
            ents.insert(make_pair(attributionName, decEntropy-ent));
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

void ID3::showTree(ID3::node *id3tree, const string &control) {
    if(id3tree == nullptr)
        id3tree = tr;
    if(id3tree->kids.size() == 0){
        if(id3tree->attribution.length() != 0)
            cout << control << id3tree->attribution <<endl;
        return;
    }
    for(auto it=id3tree->kids.begin(); it != id3tree->kids.end(); ++it){
        cout << control << id3tree->attribution << "=" <<(*it).first << endl;
        if((*it).second != nullptr)
            showTree((*it).second,control+"|   ");
    }
}