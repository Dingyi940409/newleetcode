#pragma once
#ifndef __showVec
#define __showVec
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

namespace showVec{
    void oneVec(const vector<int>& v){
        
    }

    void twoVec(const vector<vector<int>>& v){
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[i].size();j++){
                cout<<setw(2) <<setfill(' ')<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


#endif