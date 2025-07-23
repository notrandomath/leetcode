/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string makeFancyString(string s) {
        string builder = "";
        char prev = '\0';
        int count = 0;
        for (char &c: s) {
            if (c != prev) {
                prev = c;
                count = 0;
            }
            if (count == 3) continue;
            builder += c;
            ++count;
        }
        return builder;
    }
};
// @lc code=end

