#include "stdc++.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums[0] >= 0 || nums.back() <= 0)
            return res;
        for (int i = 0; nums[i] < 0; i++)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[r] + nums[l] > 0)
                    r--;
                else if (nums[i] + nums[r] + nums[l] < 0)
                    l++;
                else
                {
                    res.emplace_back(vector({nums[i], nums[r], nums[l]}));
                }
            }
        }
        return res;
    }
};