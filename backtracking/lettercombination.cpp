// figure out all the letter combination

#include <bits/stdc++.h>
using namespace std;

// This is 1 st stage. dialer building
class Solution {
public:
    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> result;

    // This is 2nd step. explore all the letter combination
    //
    void backtrack(string& digits, int index, string& path) {
        // Base case
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            path.push_back(c);              // choose
            backtrack(digits, index + 1, path); // explore
            path.pop_back();                // un-choose (backtrack)
        }
    }

    // This is 3rd stage. working solution
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;

        string path;
        backtrack(digits, 0, path);
        return result;
    }
};
 // This is 4 th stage.
int main() {
    Solution sol;
    string digits = "23";

    vector<string> ans = sol.letterCombinations(digits);

    for (string s : ans)
        cout << s << " ";

    return 0;
}
