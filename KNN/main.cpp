#include <iostream>
#include "HandwritingRecognition.h"

int main() {
    auto files =
            getFiles("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
    auto d=loadData("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
    for (int i = 0; i < d.size(); ++i) {
        for (int j = 0; j < d[0].size(); ++j) {
            cout << char(d[i][j]) << ' ';
        }
        cout << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}