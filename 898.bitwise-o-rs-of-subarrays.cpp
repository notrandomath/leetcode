/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

#include<unordered_set>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> total;
        unordered_set<int> cur_set;
        unordered_set<int> next_set;
        for (const int & cur_num: arr) {
            for (const int & val: cur_set) {
                next_set.insert(val | cur_num);
                total.insert(val | cur_num);
            }
            cur_set = next_set;
            cur_set.insert(cur_num);
            next_set = unordered_set<int>();
            total.insert(cur_num);
        }
        return total.size();
    }
};
// @lc code=end

