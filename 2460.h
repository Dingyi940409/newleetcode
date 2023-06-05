#pragma once
#ifndef __LC2460
#define __LC2460
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

namespace test2460
{
    vector<int> applyOperations(vector<int> &nums)
   {
        vector<int> ret;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]== nums[i+1]){
                nums[i] = nums[i] *2;
                nums[i+1] = 0;
            }
            if(nums[i]!=0)
                ret.push_back(nums[i]);
        }
        if(nums[nums.size()-1]!=0)
            ret.push_back(nums[nums.size()-1]);
        for(int i = ret.size();i<nums.size();i++)
            ret.push_back(0);
        return ret;
    }
    
    

    void test(){
        vector<int> v {1,2,2,1,1,0};
        applyOperations(v);
    }
}

#endif