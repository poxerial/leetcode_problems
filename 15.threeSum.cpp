#include "stdc++.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3 || nums[0] > 0 || nums.back() < 0)
            return res;
        for (size_t i = 0; nums[i] <= 0 && i < nums.size();)
        {
            size_t l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[r] + nums[l] > 0)
                    r--;
                else if (nums[i] + nums[r] + nums[l] < 0)
                    l++;
                else
                {
                    res.emplace_back(vector<int>({nums[i], nums[r], nums[l]}));
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                    r--;
                    while (nums[r] == nums[r + 1] && l < r)
                        r--;
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        return res;
    }
};

int main()
{
    vector<int> vi;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vi.push_back(temp);
    }
    Solution s;
    auto res = s.threeSum(vi);
    for (const auto& v : res)
    {
        for (auto e : v)
            cout << e << ' ';
        cout <<endl;
    }
}