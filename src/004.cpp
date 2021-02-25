//
// Created by 李毅 on 2021/2/26.
//

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int count = nums1.size() + nums2.size();
        int min = 0;
        int max = 0;
        if (count % 2 == 0) {
            min = count / 2 - 1;
            max = min + 1;
        } else {
            min = (count + 1) / 2 - 1;
            max = min;
        }

        if (nums1.size() == 0 && nums2.size() == 1) {
            return nums2[0];
        } else if (nums1.size() == 1 && nums2.size() == 0) {
            return nums1[0];
        }

        vector<int> vec;
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();
        for (int count = 2;;) {

        }
        return 0.0;
    }
};