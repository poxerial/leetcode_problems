#include "stdc++.h"

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const char *reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < 13; j++)
            {
                if (reps[j][0] == s[i] && reps[j][1] == '\0')
                    res += values[j];
                else if (reps[j][0] == s[i] && reps[j][1] == s[i + 1] && i != s.size() - 1)
                {
                    res += values[j];
                    i++;
                    break;
                }
            }
        }
        return res;
    }
};
