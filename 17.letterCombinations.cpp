#include "stdc++.h"

using namespace std;
vector<string> alphabet = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "xyz"};
class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        
        vector<string> res;
        int k = digits.size() - 1;
        while (k >= 0)
        {
            
        }

    }

    vector<string> lc(const string& digits, string prefix, vector<string> res, int i)
    {
        vector<string> res;
        for (int j = 0; j < alphabet[i].size(); j++)
        {
            res = res + lc(digits, prefix+alphabet[digits[i] - '0'][j], res, i + 1);
            
        }
    }

};