/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <ranges>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto v = 
            views::cartesian_product(nums | views::enumerate, 
                nums | views::enumerate)
            | views::filter([&target](const auto& enum_pair) {
                auto index1 = get<0>(get<0>(enum_pair));
                auto index2 = get<0>(get<1>(enum_pair));
                return index1 != index2;
            })
            | views::filter([&target](const auto& enum_pair) {
                auto value1 = get<1>(get<0>(enum_pair));
                auto value2 = get<1>(get<1>(enum_pair));
                return value1 + value2 == target;
            });
        const auto& enum_ans_pair = *v.begin();
        return {static_cast<int>(get<0>(get<0>(enum_ans_pair))), 
            static_cast<int>(get<0>(get<1>(enum_ans_pair)))};
    }
};
// @lc code=end

