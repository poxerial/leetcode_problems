#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        char ch = '\0';
        int i = 0, j = 0;
        for (; i < s.size() && j < p.size();)
        {
            if (p[j] == '.')
            {
                ch = '.';
                i++;
                j++;
            }
            else if (p[j] == '*')
            {
                if (ch == '.')
                {
                    if (p[j + 1] == '\0')
                        return true;
                    size_t right = min(p.find_first_of('.', j + 1), p.find_first_of('*', j + 1));
                    right = min(right, p.size());
                    i = s.find_first_of(p.substr(j + 1, right - j - 1));
                    if (i == string::npos)
                        return false;
                    i += right - j - 1;
                    j = right;
                }
                if (p[j + 1] == ch)
                    while (p[j + 1] == ch && s[i] == ch)
                    {
                        j++;
                        i++;
                    }
                while (s[i] == ch)
                {
                    i++;
                }
                j++;
                ch = '\0';
            }
            else
            {
                if (s[i] != p[j])
                    if (p[j + 1] != '*')
                        return false;
                    else
                    {
                        j += 2;
                        continue;
                    }
                ch = p[j];
                i++;
                j++;
            }   
        }
        if (p[j] != '\0' || s[i] != '\0')
            return false;
        return true;
    }

    bool is_match(const string &s, int bs, const string &p, int bp)
    {
        if (bp == p.length())
            return bs == s.length();
        bool isfirstmatch = (bs < s.length()) && (s[bs] == p[bp] || p[bp] == '.');

        if (bp < p.length() - 1 && p[bp + 1] == '*')
        {
            return is_match(s, bs, p, bp + 2) || isfirstmatch && is_match(s, bs + 1, p, bp);
        }
        else
        {
            return isfirstmatch && is_match(s, bs + 1, p, bp + 1);
        }
    }
};

int main()
{
    Solution so;
    string s, p;
    cin >> s >> p;
    cout << (so.isMatch(s, p) ? "true" : "false") << endl;
}