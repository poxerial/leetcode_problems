#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            return (nums2[nums2.size() / 2] + nums2[(nums2.size() - 1) / 2]) / 2.0;
        else if (nums2.empty())
            return (nums1[nums1.size() / 2] + nums1[(nums1.size() - 1) / 2]) / 2.0;
        
    }

    
};