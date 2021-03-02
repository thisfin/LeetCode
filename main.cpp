#include <iostream>
#include <vector>
#include "src/0006.cpp"

using namespace std;

int main() {
    vector<vector<char>> v = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    cout << Solution().convert("PAYPALISHIRING", 4) << endl;
    cout << Solution().convert("A", 1) << endl;
    return 0;
}
