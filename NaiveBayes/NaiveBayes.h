//
// Created by squarefong on 18-4-14.
//

#ifndef NAIVEBAYES_NAIVEBAYES_H
#define NAIVEBAYES_NAIVEBAYES_H

#include <map>
#include <iomanip>
#include "loadData.h"
using namespace std;


class NaiveBayes {
    Instances dataSets;
    //the attribute to use as the class
    int decAttribution;
    map<string, double> decisionAttributionCounter;

    class NBClass{
    public:
        class Attributions{
        public:
            map<string, int> attributes;
            vector<double> probability;
            explicit Attributions(const vector<string> &allAttributions){
                probability = vector<double>(allAttributions.size(),0.0);
                for(int i = 0; i != allAttributions.size(); ++i){
                    attributes.insert(make_pair(allAttributions[i], i));
                }
            }
            double& operator[](const string & attribute){
                if(attributes.find(attribute) != attributes.end()){
                    return probability[attributes[attribute]];
                } else{
                    cerr << "attribute does not exist\n";
                    exit(1);
                }
            }
        };

        map<string,map<string,int> > decisionAttributes;
        vector<Attributions> attributions;
        NBClass(Instances& allData, int decisionAttribution){
            //获取决策向量
            set<string> dec = allData.getAttributions(decisionAttribution);
            //int i=0;
            vector<string> classes;
            for(auto it = dec.begin(); it != dec.end(); ++it){
                classes.push_back(*it);
            }
            Attributions c(classes);
            for(unsigned i = 0; i < allData.attributionSize(); ++i){
//                if(i == decisionAttribution)
//                    continue;
                set<string> temp = allData.getAttributions(i);
                map<string,int> p;
                for (const auto &it : temp) {
                    p.insert(make_pair(it,attributions.size()));
                    attributions.push_back(c);
                }
                decisionAttributes.insert(make_pair(allData.getAttributionName(i), p));
            }

        }
        NBClass() = default;

        Attributions &operator[](const string & attribute){
            int i = 0;
            for(;i < attribute.length(); ++i){
                if(attribute[i] == '=')
                    break;
            }
            string attributeName = attribute.substr(0,i);
            string attributeValue = attribute.substr(i+1);
//            if(decisionAttributes.find(attributeName) != decisionAttributes.end()){
//                return attributions[decisionAttributes[attributeName][attributeValue]];
//            } else{
//                cerr << "attribute does not exist\n";
//                exit(1);
//            }

            return attributions[decisionAttributes[attributeName][attributeValue]];
        }

        friend ostream& operator<<(ostream & os, const NBClass&rhs){
            os << setw(12) << " " ;
            Attributions t = (*rhs.attributions.begin());
            for(auto it = t.attributes.begin(); it != t.attributes.end(); ++it){
                os << setw(10) << (*it).first;
            }
            os << endl;
            for(auto it = rhs.decisionAttributes.begin(); it != rhs.decisionAttributes.end(); ++it){
                os << (*it).first << '\n';
                map<string, int> t1 = (*it).second;
                for(auto it2 = t1.begin(); it2 != t1.end(); ++it2){
                    Attributions temp=rhs.attributions[(*it2).second];
                    os << " "  << setw(10) << (*it2).first << " ";
                    for(auto j = temp.probability.begin(); j!=temp.probability.end(); ++j){
                        os << setw(10) << (*j);
                    }
                    os << endl;

                }
            }
            return os;
        }
    };

    NBClass nbClass;
public:
    explicit NaiveBayes(const string&filePath, int decisionAttr=0):decAttribution(decisionAttr){
        DataLoader::ArffReader(filePath,dataSets);
        //nbClass = NBClass(dataSets, decisionAttr);
    }

    explicit NaiveBayes(const Instances & rhs, int decisionAttr=0):decAttribution(decisionAttr){
        dataSets=rhs;
        //nbClass = NBClass(dataSets, decAttribution);
    }

    bool setDec(unsigned n);

    int getDecisionAttribution(){
        return decAttribution;
    }

    void buildNBTree();

    string judge(const vector<string> &rhs);
};


#endif //NAIVEBAYES_NAIVEBAYES_H
