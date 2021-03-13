//
// Created by 李毅 on 2021/3/13.
//

#include <vector>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {
    }

//todo: 用二叉树优化
    void add(int key) {
        vector<int>::iterator iter = lower_bound(values.begin(), values.end(), key);
        if (iter != values.end()) {
            if (*iter != key) {
                values.insert(iter, key);
            }
        } else {
            values.push_back(key);
        }
    }

    void remove(int key) {
        vector<int>::iterator iter = lower_bound(values.begin(), values.end(), key);
        if (iter != values.end() && *iter == key) {
            values.erase(iter);
        }
    }

    bool contains(int key) {
        vector<int>::iterator iter = lower_bound(values.begin(), values.end(), key);
        if (iter != values.end() && *iter == key) {
            return true;
        }
        return false;
    }

private:
    vector<int> values;
};
