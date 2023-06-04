#pragma once
#ifndef __LC2559
#define __LC2559
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
namespace test2559
{

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> ret(words.size(), 0);
        vector<int> ret1(words.size(), 0);
        int all = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string t = words[i];
            int tl = t.size();
            char s = t[0];
            char e = t[tl - 1];
            if ((s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') &&
                (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u'))
            {
                all++;
                ret1[i]++;
            }
            ret[i] = all;
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int s = queries[i][0];
            int e = queries[i][1];
            int mark = 0;
            if (ret1[s] == 1)
                mark = 1;
            int sum = ret[e] - ret[s] + mark;

            ans.push_back(sum);
        }

        return ans;
    }

    void test(){
        vector<string> words {"aba","bcb","ece","aa","e"};
        vector<vector<int>> queries {{0,2},{1,4},{1,1}};
        vowelStrings(words,queries);
    }

}

#endif