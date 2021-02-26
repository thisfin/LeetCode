//
// Created by 李毅 on 2021/2/26.
//

#include <vector>
#include <iostream>

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

        vector<int> vec;
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();

        for (int count = 0;; ++count) {
            int value;
            if (iter1 == nums1.end()) {
                value = *iter2;
                ++iter2;
            } else if (iter2 == nums2.end()) {
                value = *iter1;
                ++iter1;
            } else if (*iter1 > *iter2) {
                value = *iter2;
                ++iter2;
            } else {
                value = *iter1;
                ++iter1;
            }

            if (count >= min) {
                vec.push_back(value);
                if (count == max) {
                    break;
                }
            }
        }

        return vec.size() == 1 ? vec[0] : ((double) (vec[0] + vec[1]) / 2);
    }
};
