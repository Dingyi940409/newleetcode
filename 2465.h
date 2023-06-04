#pragma once
#ifndef __LC2465
#define __LC2465
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

namespace test2465
{

    int distinctAverages(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        map<float, int> m;
        sort(nums.begin(), nums.end());
        int endPos = nums.size() - 1;
        int startPos = 0;
        for (; startPos < endPos; startPos++, endPos--)
        {
            float temp = (nums[endPos] + nums[startPos]) / 2.0;
            m[temp]++;
        }
        return m.size();
    }

    int test(){
        vector<int> nums {4,1,4,0,3,5};
        distinctAverages(nums);
    }
}

#endif