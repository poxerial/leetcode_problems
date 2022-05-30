#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string rt;
        int length = 0;
        size_t size = s.size();
        for (size_t i = 0; i < size * 2 - 1; i++)
        {
            for (size_t j = 0;; j++)
            {
                if ((i + 1) / 2 + j == size || i / 2 - j == -1 ||
                    s[(i + 1) / 2 + j] != s[i / 2 - j])
                {
                    int len = (i + 1) / 2 + 2 * j - i / 2 - 1;
                    if (len > length)
                    {
                        length = len;
                        rt = s.substr(i / 2 - j + 1, length);
                    }
                    break;
                }
            }
        }
        return rt;
    }
};

int main()
{
    string s = "adbfffbafa";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}