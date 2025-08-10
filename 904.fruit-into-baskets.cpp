/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int maxSize = 0;
        map<int, int> last_index;
        for (int r = 0; r < fruits.size(); ++r) {
            int type = fruits[r];
            if (!last_index.contains(type) && last_index.size() == 2) {
                int min_key_val = -1;
                int min_val = INT32_MAX;
                for (const auto& pair : last_index) {
                    if (pair.second < min_val) {
                        min_val = pair.second;
                        min_key_val = pair.first;
                    }
                }
                l = min_val+1;
                last_index.erase(min_key_val);
            }
            last_index[type] = r;
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
// @lc code=end

