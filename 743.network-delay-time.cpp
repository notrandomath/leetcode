/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

#include<vector>
using namespace std;
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<iostream>

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjacency_map;
        for (const vector<int>& edge: times) {
            adjacency_map[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }
        unordered_set<int> visited;
        auto cmp = [](const pair<int, int> left, const pair<int, int> right) { return left.second > right.second; };
        priority_queue<pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> to_visit(cmp);
        int max_cost = 0;
        to_visit.push({k, 0});
        while (!to_visit.empty() && visited.size() != n) {
            const auto [cur, cur_cost] = to_visit.top();
            to_visit.pop();
            if (visited.contains(cur))
                continue;
            visited.insert(cur);
            max_cost = max(cur_cost, max_cost);
            for (const auto& [v, v_cost] : adjacency_map[cur]) {
                to_visit.push({v, cur_cost + v_cost});
            }
        }
        return visited.size() == n ? max_cost : -1;
    }
};
// @lc code=end

