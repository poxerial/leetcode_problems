#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty())
            return (nums2[nums2.size() / 2] + nums2[(nums2.size() - 1) / 2]) / 2.0;
        else if (nums2.empty())
            return (nums1[nums1.size() / 2] + nums1[(nums1.size() - 1) / 2]) / 2.0;
        return (findNthNum(nums1, nums2, (nums1.size() + nums2.size() + 2) / 2) 
        + findNthNum(nums1, nums2, (nums1.size() + nums2.size() + 1) / 2)) / 2.0;
    }

    int findNthNum(vector<int> &nums1, vector<int> &nums2, size_t nth)
    {
        size_t n1 = 0, n2 = 0;
        for (;; nth -= nth / 2)
        {
            if (n1 >= nums1.size())
                return nums2[n2 + nth - 1];
            if (n2 >= nums2.size())
                return nums1[n1 + nth - 1];
            if (nth == 1)
                return min(nums1[n1], nums2[n2]);
            int nums1_median = nums1.size() > n1 + nth / 2 - 1 ? 
            nums1[n1 + nth / 2 - 1] : INT_MAX;
            int nums2_median = nums2.size() > n2 + nth / 2 - 1 ? 
            nums2[n2 + nth / 2 - 1] : INT_MAX;
            if (nums1_median < nums2_median)
                n1 += nth / 2;
            else
                n2 += nth / 2;
        }
        return 0.0;
    }
};