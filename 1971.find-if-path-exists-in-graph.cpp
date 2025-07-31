/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        unordered_set<int> source_set;
        unordered_set<int> dest_set;
        source_set.insert(source);
        dest_set.insert(destination);
        while (true) {
            int prev_source_size = source_set.size();
            int prev_dest_size = dest_set.size();
            for (vector<int>& edge : edges) {
                if (dest_set.contains(edge[1])) dest_set.insert(edge[0]);
                if (dest_set.contains(edge[0])) dest_set.insert(edge[1]);
                if (source_set.contains(edge[1])) source_set.insert(edge[0]);
                if (source_set.contains(edge[0])) source_set.insert(edge[1]);
                if (dest_set.contains(edge[1]) && source_set.contains(edge[0])
            || dest_set.contains(edge[0]) && source_set.contains(edge[1])) {
                    return true;
                }
            }
            // no change = break
            if (prev_source_size == source_set.size() && prev_dest_size == dest_set.size()) break;
        }
        return false;
    }
};
// @lc code=end

