#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        size_t stride = numRows * 2 - 2;
        string rt;
        if (numRows == 1){
            return s;
        }
        if (numRows == 2){
            for (int i = 0; 2 * i < s.size(); i++)
                rt.push_back(s[2 * i]);
            for (int i = 0; 2 * i + 1 < s.size(); i++)
                rt.push_back(s[2 * i + 1]);
            return rt;
        }
        for (size_t i = 0; i * stride < s.size(); i++) 
            rt.push_back(s[i * stride]);
        for (size_t i = 1; i < numRows - 1; i++)
            for (size_t j = 0;; j++)
            {
                if (j * stride + i < s.size())
                    rt.push_back(s[j * stride + i]);
                else
                    break;
                if ((j + 1) * stride - i < s.size())
                    rt.push_back(s[(j + 1) * stride - i]);
            }
        if  (numRows - 1 < s.size())
            rt.push_back(s[numRows - 1]);
        for (size_t i = 1; i * stride + numRows - 1 < s.size(); i++)
            rt.push_back(s[i * stride + numRows - 1]);
        return rt;
    }
};

int main()
{
    string str = "ABCDEF";
    Solution s;
    cout << s.convert(str, 5) << endl;
}
