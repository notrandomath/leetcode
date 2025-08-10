/*
 * @lc app=leetcode id=3477 lang=cpp
 *
 * [3477] Fruits Into Baskets II
 */

#include<vector>
#include<list>
using namespace std;

// @lc code=start
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        list<int> basket_ll{baskets.begin(), baskets.end()};
        int num_skipped = 0;
        for (const int& fruit: fruits) {
            bool found = false;
            for (auto it = basket_ll.begin(); it != basket_ll.end(); ++it) {
                if (*it >= fruit) {
                    basket_ll.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) ++num_skipped;
        }
        return num_skipped;
    }
};
// @lc code=end

