/*
 * @lc app=leetcode id=2411 lang=cpp
 *
 * [2411] Smallest Subarrays With Maximum Bitwise OR
 */

#include<vector>
#include<deque>
#include<array>
using namespace std;

// @lc code=start
class Solution {
public:
    void modifyBin(int* bin, int value, bool add) {
        for (int i = 0; i < 32; ++i) {
            if (value & (1 << i)) bin[i] += (add ? 1 : -1);
        }
    }

    bool checkEquality(int* bin, int* target) {
        for (int i = 0; i < 32; ++i) {
            if (bin[i] == 0 && target[i] > 0) return false;
            if (bin[i] > 0 && target[i] == 0) return false;
        }
        return true;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        deque<int> maxOr;
        maxOr.push_back(nums[nums.size()-1]);
        for (int i = nums.size()-2; i >= 0; --i) {
            maxOr.push_front(maxOr[0] | nums[i]);
        }

        vector<int> ans;
        int r = 0;
        int curBin[32] = {};
        for (int l = 0; l < nums.size(); ++l) {
            if (l > r) ++r;
            int target[32] = {};
            modifyBin(target, maxOr[l], true);
            while (!checkEquality(curBin, target)) {
                if (r >= nums.size()) throw runtime_error("r out of bounds");
                modifyBin(curBin, nums[r], true);
                ++r;
            }
            ans.push_back(maxOr[l] == 0 ? 1 : r-l);
            modifyBin(curBin, nums[l], false);
        }
        return ans;
    }
};
// @lc code=end

