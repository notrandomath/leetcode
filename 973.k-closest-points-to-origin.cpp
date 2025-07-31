/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include<vector>
#include<algorithm>
#include <ranges>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](const vector<int>& point) {return make_tuple(pow(point[0], 2)+pow(point[1], 2), point[0], point[1]);};
        vector<tuple<double, int, int>> distances = points | ranges::views::transform(distance) | ranges::to<vector>();
        auto distance_compare = [](
            const std::tuple<double, int, int>& a,
            const std::tuple<double, int, int>& b) {
            return std::get<0>(a) < std::get<0>(b);
        };
        make_heap(distances.begin(), distances.end(), distance_compare);
        vector<vector<int>> k_closest;
        for (int i = 0; i < k; ++i) {
            k_closest.push_back({get<1>(distances.front()), get<2>(distances.front())});
            pop_heap(distances.begin(), distances.end(), distance_compare); distances.pop_back();
        }
        return k_closest;
    }
};
// @lc code=end

