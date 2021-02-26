//
// Created by 李毅 on 2021/2/26.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        unordered_map<int, int> hash; // 使用 hash 存储可以去重
        for (string word : words) {
            hash[sToInt(word)]++;
        }

        vector<int> result;
        for (string puzzle: puzzles) {
            int i = 0;
            int first = cToInt(puzzle[0]);
            int puzzle2 = sToInt(puzzle);
            for (int num = puzzle2; num; num = (num - 1) & puzzle2) { // 这种遍历的方式最快
                if ((first & num) == first) {
                    i += hash[num];
                }
            }
            result.push_back(i);
        }
        return result;
    }

private:
    int sToInt(string word) {
        int i = 0;
        for (char c: word) {
            i |= cToInt(c);
        }
        return i;
    }

    int cToInt(char c) {
        return 1 << ((int) c - 97);
    }
};
