#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool positive = true;
        for (; i < s.size() && s[i] == ' '; i++) {}
        if (s[i] == '-')
        {
            positive = false;
            i++;
        }
        else if (s[i] == '+')
            i++;
        s=s.substr(i);
        double res = 0.0;
        for (auto ch : s)
        {
            if (ch > '9' || ch < '0')
                break;
            res *= 10;
            res += ch - '0';
        }
        return positive ? min<double>(res, INT_MAX) : max<double>(-res, INT_MIN);
    }
};