#include <iostream>
#include <vector>
#include "src/0042.cpp"

using namespace std;

int main() {
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    v = {4, 2, 0, 3, 2, 5};
    v = {4, 2, 3};
    cout << Solution().trap(v) << endl;
    return 0;
}
