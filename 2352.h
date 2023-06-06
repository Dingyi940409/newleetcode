#pragma once
#ifndef __LC2352
#define __LC2352
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include"showVec.h"
using namespace std;

namespace test2352
{
    int equalPairs(vector<vector<int>> &grid)
    {
        vector<vector<int>> other;
        int len = grid.size();
        for(int col = 0;col<len;col++){
            vector<int> temp;
            for(int row = 0;row<len;row++){
                temp.push_back(grid[row][col]);
            }
            other.push_back(temp);
        }
        int ret = 0;
        for(int i =0;i<len;i++){
            for(int k = 0;k<len;k++){
                if(grid[i]== other[k])
                    ret++;
            }
        }
        return ret;
    }

    void test()
    {
        vector<vector<int>> v{{3,3,3,6,18,3,3,3,3,3},{3,3,3,3,1,3,3,3,3,3},{3,3,3,3,1,3,3,3,3,3},
                            {3,3,3,3,1,3,3,3,3,3},{1,1,1,11,19,1,1,1,1,1},{3,3,3,18,19,3,3,3,3,3},{3,3,3,3,1,3,3,3,3,3},
                            {3,3,3,3,1,3,3,3,3,3},{3,3,3,1,6,3,3,3,3,3},{3,3,3,3,1,3,3,3,3,3}};
        showVec::twoVec(v);
        int ret = equalPairs(v);
        cout<<ret<<endl;
    }
}

#endif