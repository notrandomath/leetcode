/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> prev;
        int max_num = INT32_MIN;
        int total = 0;
        for (int& num : nums) {
            if (num > max_num) max_num = num;
            if (num > 0 & !prev.contains(num)) {
                prev.insert(num);
                total += num;
            }
        }
        return prev.empty() ? max_num : total;
    }
};
// @lc code=end

