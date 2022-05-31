#include "stdc++.h"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int i = 0;
        for (; i < strs[0].size(); i++)
        {
            for (int j = 0; j + 1 < strs.size(); j++)
                if ((i == strs[j].size() || i == strs[j + 1].size()) || strs[j][i] != strs[j + 1][i])
                    return strs[0].substr(0, i);
        }
        return strs[0];
    }
};