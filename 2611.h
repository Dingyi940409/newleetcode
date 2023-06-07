#pragma once
#ifndef __LC2611
#define __LC2611
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include "showVec.h"
using namespace std;

namespace test2611
{
    // 十分丑陋的一种写法。脑子有点僵硬。 总想着把间隔最大的拿出来，然后再顺序处理
    // 其实直接加上数字间隔就是 -R2 + R1 的值。
    // 所以 由此可以衍生出 直接对间隔值进行排序，然后直接让sumR2的和逐次添加间隔值。就是 最大值
    // 因为 sum + diff  == sum - R2min + R1max  
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        if (k == reward1.size())
        {
            return accumulate(reward1.begin(), reward1.end(), 0);
        }

        int ret = 0;
        int sum = accumulate(reward2.begin(), reward2.end(), 0);

        //vector<vector<int>> gap;
        map<int,vector<int>> gap;
        for (int i = 0; i < reward1.size(); i++)
        {
            // vector<int> temp;
            // temp.push_back(reward1[i] - reward2[i]);
            // temp.push_back(i);
            // gap.push_back(temp);
            int dis = reward1[i] - reward2[i];
            if(gap.find(dis) != gap.end()){
                auto t = gap.find(dis);
                t->second.push_back(i);
            }else{
                vector<int> temp;
                temp.push_back(i);
                gap[dis] = temp;
            }
        }
        // sort(gap.begin(), gap.end(), [](vector<int> a, vector<int> b)
        //      { return a[0] > b[0]; });
        auto iter = --gap.end();
        while(k>0){
            vector<int> temp = iter->second;
            int len = temp.size();
            int minLen = k > len ? len:k;
            for(int i = 0;i<minLen;i++){
                int index = temp[i];
                sum = sum - reward2[index] + reward1[index];
            }
            k = k-minLen;
            iter--;
        }

        for (int i = 0; i < k; i++)
        {
            vector<int> temp = gap[i];
            int index = temp[1];
            sum = sum - reward2[index] + reward1[index];
        }
        return sum;
    }


    int miceAndCheese1(vector<int> &reward1, vector<int> &reward2, int k){
        vector<int> diff;
        int sum = 0;
        int len = reward1.size();
        for(int i =0;i<len;i++){
            diff.push_back(reward1[i]- reward2[i]);
            sum+=reward2[i];
        }
        sort(diff.begin(),diff.end());
        for(int i = 1;i<=k;i++){
            sum+=diff[len - i];
        }
        return sum;
    }
    void test()
    {
        vector<int> v1{1, 1, 3, 4};
        vector<int> v2{4, 4, 1, 1};
        int k = 2;
        int a = miceAndCheese1(v1, v2, k);
        cout << a << endl;
    }
}

#endif