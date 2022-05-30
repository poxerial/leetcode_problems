#include "stdc++.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int h = min(height[r], height[l]);
        int area_max = h * (r - l);
        for (; l < r;)
        {
            if (height[r] < height[l])
                r--;
            else
                l++;
            h = min(height[r], height[l]);
            area_max = max(area_max, h * (r - l));
        }
        return area_max;
    }
};