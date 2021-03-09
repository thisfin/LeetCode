//
// Created by 李毅 on 2021/3/4.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> v1, vector<int> v2) {
            return v1[0] > v2[0] && (v1[1] <= v2[1]);
        });

        for (vector<vector<int>>::iterator iter = envelopes.begin(); iter != envelopes.end(); ++iter) {
            lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

            upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。


            ————————————————
            版权声明：本文为CSDN博主「brandong」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
            原文链接：https://blog.csdn.net/qq_40160605/article/details/80150252
        }
    }
};
