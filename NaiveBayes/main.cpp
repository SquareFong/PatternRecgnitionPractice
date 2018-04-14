#include <iostream>
#include "loadData.h"
int main() {
    Instances i;
    DataLoader::ArffReader("/opt/weka-3-8-2/data/weather.nominal.arff",i);
    cout << i;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}