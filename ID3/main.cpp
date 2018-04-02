#include <iostream>
#include "loadData.h"
#include "ID3.h"
int main() {
    Instances i;
    DataLoader::ArffReader("/opt/weka-3-8-2/data/weather.nominal.arff",i);
    ID3 id3(i);
    vector<int> s;
    for(int j=0; j<i.size(); ++j){
        s.push_back(j);
    }
    id3.setDec(4);
    cout << id3.entropy(s,"play");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}