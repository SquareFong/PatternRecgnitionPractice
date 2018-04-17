#include <iostream>
#include "HandwritingRecognition.h"

string trainingDirectory("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
string testDirectory("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/testDigits");

int main() {
    vector<string> trainingFiles = getFiles(trainingDirectory);
    vector<vector<int>> trainingSet = loadData(trainingDirectory);
    vector<string> testFiles = getFiles(testDirectory);
    vector<vector<int>> testSet = loadData(testDirectory);

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

    return 0;
}