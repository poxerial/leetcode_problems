#include "stdc++.h"

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const char* reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        while (num > 0)
            for (int i = 0; i < 13; i++)
                if (values[i] <= num)
                {
                    res.append(reps[i]);
                    num -= values[i];
                    break;
                }
        return res;
    }
};

int main()
{
    Solution s;
    int a;
    cin >> a;
    cout << s.intToRoman(a) << endl;
}