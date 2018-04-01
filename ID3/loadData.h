//
// Created by squarefong on 18-4-1.
//

#ifndef ID3_LOADDATA_H
#define ID3_LOADDATA_H

#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <cstring>
using namespace std;

class Instance{
    vector<string> attributionsValue; //一个实例的所有属性
    vector<int> numericSub; //属性为数值的下标们
public:
    Instance(unsigned attributionNumber, const vector<int> &NumericSub=vector<int>()){
        attributionsValue =vector<string>(attributionNumber,"");
        this->numericSub=NumericSub;
    }
    Instance(const vector<string> & AttributionsValue){
        attributionsValue = AttributionsValue;
    }
    string operator[](const int &rhs)const{
        if(rhs>=attributionsValue.size())
            return "";
        return attributionsValue[rhs];
    }

};

class Instances{
    vector<Instance> dataSets;
    vector<set<string>> attributions;
    vector<string> attributionsName;
public:
    Instances(){}
    Instances(const vector<set<string>> &Attributions, const vector<string> &AttributionsName){
        attributions = Attributions;
        attributionsName = AttributionsName;
    }
    void push_back(const Instance& data){
        dataSets.push_back(data);
    }
    Instance operator[](const int &rhs)const{
        if(rhs >= dataSets.size())
            exit(1);
        return dataSets[rhs];
    }

    friend ostream &operator << (ostream & ost,const Instances&rhs){
        for(int i=0; i<rhs.attributionsName.size(); ++i){
            cout << "@attribute " << rhs.attributionsName[i] << " {";
            auto it = rhs.attributions[i].begin();
            cout << (*it);
            ++it;
            while(it != rhs.attributions[i].end()){
                cout << ',' << (*it);
                ++it;
            }
            cout << "}\n";
        }
        cout << endl << "@data\n";
        for(int i=0; i<rhs.dataSets.size(); ++i){
            cout << rhs.dataSets[i][0];
            for(int j=1; j<rhs.attributions.size(); ++j){
                cout << "," << rhs.dataSets[i][j];
            }
            cout << endl;
        }

        return ost;
    }
};
class DataLoader{
public:
    static bool ArffReader(const string &filePath, Instances &instances){
        ifstream ifstream1(filePath);
        char singleLine[256];
        memset(singleLine,0,256);
        vector<set<string>> attributions;
        vector<string> attributionsName;
        while(ifstream1.getline(singleLine,256)){
            if(strlen(singleLine) ==0 )
                continue;
            string temp(singleLine);
            //添加属性
            if(temp[0] == '@'){
                //@attribute
                if(temp[1] == 'a'){
                    unsigned beginSub=11;
                    unsigned endSub=12;
                    while((temp[endSub] >= 'a'&&temp[endSub] <='z') || (temp[endSub] >='A' && temp[endSub] <='Z') )
                        ++endSub;
                    string attributionName=temp.substr(beginSub,endSub-beginSub);
                    attributionsName.push_back(attributionName);

                    set<string> attr;
                    while(true) {
                        //截取一个单词
                        while (!((temp[endSub] >= 'a' && temp[endSub] <= 'z') ||
                                 (temp[endSub] >= 'A' && temp[endSub] <= 'Z')))
                            ++endSub;
                        beginSub = endSub;
                        while ((temp[endSub] >= 'a' && temp[endSub] <= 'z') ||
                               (temp[endSub] >= 'A' && temp[endSub] <= 'Z'))
                            ++endSub;
                        attr.insert(temp.substr(beginSub,endSub -beginSub));

                        if(temp[endSub] == '}')
                            break;
                    }
                    attributions.push_back(attr);
                }
                if(temp[1]=='d'){
                    instances=Instances(attributions,attributionsName);
                }
            }
            if((temp[0] >= 'a'&&temp[0] <='z') || (temp[0] >='A' && temp[0] <='Z') || (temp[0] >='0' && temp[0] <='9')){
                unsigned beginSub=0;
                unsigned endSub=1;
                vector<string> tempInstance;
                for(endSub=1; endSub < temp.length(); ++endSub){
                    if(temp[endSub] == ','){
                        tempInstance.push_back(temp.substr(beginSub,endSub-beginSub));
                        beginSub=endSub+1;
                    }
                }
                tempInstance.push_back(temp.substr(beginSub,endSub-beginSub));
                instances.push_back(tempInstance);
            }
        }
    }
};

#endif //ID3_LOADDATA_H
