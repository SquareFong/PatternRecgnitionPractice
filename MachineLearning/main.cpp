#include <iostream>
#include <dirent.h>
#include <algorithm>
#include <fstream>
#include <random>
#include "artificialNeuron.h"
#include "neuralNetwork.h"
using namespace std;


vector<string> getFiles(const string &directory)
{
    vector<string> files;//存放文件名
    DIR *dir= nullptr;
    struct dirent *entry;
    char path[1000];
    if ((dir=opendir(directory.c_str())) == nullptr)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((entry = readdir(dir)) != nullptr) {
        if(entry->d_name[0] != '.'){
            files.emplace_back(entry->d_name);
        }
    }

    closedir(dir);
    sort(files.begin(),files.end());
    return files;
}

vector<vector<double>> loadData(string directory){
    vector<string> files = getFiles(directory);
    if(directory[directory.length()-1] != '/'){
        directory += '/';
    }
    vector<vector<double>> data;
    for(auto &file : files){
        vector<double> temp;
        ifstream infile(directory+file);
        char c;
        while(infile.get(c)){
            if(c == '\n')
                continue;
            temp.emplace_back(c-'0');
        }
        data.push_back(temp);
        infile.close();
    }
    return data;
}

string trainingDirectory("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/trainingDigits");
string testDirectory("/home/squarefong/Documents/PatternRecgnitionPractice/KNN/testDigits");

int main() {
//    ArtificialNeuron an;
//    vector<double> w;
//    w.push_back(0.5);
//    w.push_back(0.55);
//    w.push_back(0.6);
//    an.setWeight(w);
//    vector<double> x;
//    x.push_back(0.593269992);
//    x.push_back(0.596884378);
//    x.push_back(1);
//    cout << an.output(x) <<endl;
//    auto f=an.updateWeight(x, 0.772928 - 0.99);
//    for(auto i:f){
//        cout << i << endl;
//    }


    vector<string> trainingFiles = getFiles(trainingDirectory);
    vector<vector<double>> trainingSet = loadData(trainingDirectory);
    vector<string> testFiles = getFiles(testDirectory);
    vector<vector<double>> testSet = loadData(testDirectory);

    ArtificialNeuron an;
    an.setWeight(vector<double>(1, 0.5));

    neuronLayer L;
    //L.layer=vector<ArtificialNeuron>(1024, an);

    BPNeuronNetwork bpn;
    //bpn.push(L);
    vector<double> wei(1024, 0);
    for(auto &w:wei){
        w=(rand()%10001)/10000.0;
    }
    an.setWeight(wei);
    L.layer=vector<ArtificialNeuron>(25, an);
    bpn.push(L);

    wei.resize(25);
    for(auto &w:wei){
        w=(rand()%10001)/10000.0;
    }
    an.setWeight(wei);
    L.layer=vector<ArtificialNeuron>(15, an);
    bpn.push(L);

    wei.resize(15);
    for(auto &w:wei){
        w=(rand()%10001)/10000.0;
    }
    an.setWeight(wei);
    L.layer=vector<ArtificialNeuron>(10, an);
    bpn.push(L);

    vector<vector<double>> targets;
    for(auto &t:testFiles){
        vector<double> tar(10, 0.01);
        tar[t[0]-'0'] += 1;
        targets.push_back(tar);
    }
    for(int i = 0; i < testSet.size(); ++i){
        int j = 10;
        while(--j){
            bpn.train(testSet[i], targets[i]);
        }
    }

    for(int j = 0; j < 10; ++j){
        cout << j * 10 << ": [";
        auto result = bpn.test(trainingSet[10*j]);
        for(auto r:result){
            cout << r << ',';
        }
        cout << "]\n";
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}