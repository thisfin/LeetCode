#include <iostream>

#include "src/0005.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<string> ss;
//    cout << *ss.begin() << endl;
    cout << (ss.begin() == ss.end() ? "yes" : "no") << endl;
    cout << "Hello" << endl;

    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};
    cout << Solution().longestPalindrome("ababbadbf") << endl;


    cout << Solution().longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa") << endl;
    return 0;
}
