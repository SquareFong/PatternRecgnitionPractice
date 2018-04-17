#include <iostream>
#include "HandwritingRecognition.h"

int main() {
    vector<string> trainingFiles = getFiles("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
    vector<vector<int>> trainingSet = loadData("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
    vector<string> testFiles = getFiles("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/testDigits");
    vector<vector<int>> testSet = loadData("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/testDigits");

    double errorCounter = 0.0;
    for(int i=0; i<testFiles.size(); ++i){
        set<int> knnSub = judge(testSet[i],trainingSet,5);
        vector<int> t(10,0);
        for(auto j:knnSub){
            ++t[trainingFiles[j][0] - '0'];
        }
        int maxSub(0);
        for(int j=0; j<t.size(); ++j){
            if(t[j] > t[maxSub])
                maxSub = j;
        }
        int result = maxSub;
        int answer = testFiles[i][0] - '0';
        cout << "对于测试文件：" << testFiles[i] << ", 分类结果：" << result << ", 正确答案：" << answer << endl;
        errorCounter += ((result == answer)?0:1);

    }

    cout << "错误率：" << errorCounter/testFiles.size() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}