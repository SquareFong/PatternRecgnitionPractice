//
// Created by squarefong on 18-4-17.
//

#ifndef KNN_HANDWRITINGRECOGNITION_H
#define KNN_HANDWRITINGRECOGNITION_H

#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <dirent.h>
#include <algorithm>
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

vector<vector<int>> loadData(string directory){
    vector<string> files = getFiles(directory);
    if(directory[directory.length()-1] != '/'){
        directory += '/';
    }
    vector<vector<int>> data;
    for(auto &file : files){
        vector<int> temp;
        ifstream infile(directory+file);
        char c;
        while(infile.get(c)){
            if(c == '\n')
                continue;
            temp.emplace_back(c);
        }
        data.push_back(temp);
        infile.close();
    }
    return data;
}

unsigned distance(const vector<int> &lhs, const vector<int> &rhs){
    unsigned d = 0;
    if(lhs.size() != rhs.size())
        return d-1;
    for(int i(0); i<rhs.size(); ++i){
        d += (lhs[i] - rhs[i]) * (lhs[i] - rhs[i]);
    }
    return d;
}

set<int> judge(const vector<int> &test, const vector<vector<int>> &trainings, int k){
    vector<unsigned > distances(trainings.size(), 0);
    for (int i = 0; i < distances.size(); ++i){
        distances[i] = distance(test, trainings[i]);
    }
    set<int> KNNSub;
    while (k--) {
        unsigned minDistance(0);
        int minSub(0);
        --minDistance;
        for(int i=0; i < distances.size(); ++i){
            if(distances[i] < minDistance){
                minDistance = distances[i];
                minSub = i;
            }
        }
        KNNSub.insert(minSub);
        unsigned temp(0);
        distances[minSub] = --temp;
    }
    return KNNSub;
}


#endif //KNN_HANDWRITINGRECOGNITION_H
