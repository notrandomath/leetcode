/*
 * @lc app=leetcode id=2106 lang=cpp
 *
 * [2106] Maximum Fruits Harvested After at Most K Steps
 */

#include<vector>
#include<array>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        size_t maxN = fruits[fruits.size()-1][0]+1;
        int* fruits_arr = (int*) malloc(maxN * sizeof(int));
        fruits_arr = (int*) memset(fruits_arr, 0, maxN*sizeof(int));
        for (const vector<int>& pair : fruits) {
            fruits_arr[pair[0]] = pair[1]; 
        }
        int maxTotal = 0;
        // going straight
        for (int i = 1; i < k; ++i) {
            int l = startPos - i;
            int r = startPos + i;
            int l_val = 0;
            int r_val = 0;
            if (l < 0 && r >= maxN) break;
            if (l >= 0) {
                if (i > 1)
                    fruits_arr[l] += fruits_arr[l+1];
                l_val = fruits_arr[l];
            }
            if (r < maxN) {
                if (i > 1)
                    fruits_arr[r] += fruits_arr[r-1];
                r_val = fruits_arr[r];
            }
            maxTotal = max(maxTotal, max(l_val, r_val));
        }
        // skipping
        for (int i = 1; i < k; ++i) {
            int l = startPos - i;
            int r = startPos + i;
            int opp_l = l + (k-i);
            int opp_r = r - (k-i);
            int skip_l = 0;
            int skip_r = 0;
            if (
                (l < 0 || opp_l <= startPos)
                && (r > maxN || opp_r >= startPos)
            ) break;
            if (l >= 0 && opp_l < maxN && opp_l > startPos) {
                skip_l = fruits_arr[l]+fruits_arr[opp_l];
            }
            if (r < maxN && opp_l >= 0 && opp_r < startPos) {
                skip_r = fruits_arr[r]+fruits_arr[opp_r];
            }
            maxTotal = max(maxTotal, max(skip_l, skip_r));
        }
        int start_fruit = fruits_arr[startPos];
        free(fruits_arr);
        return maxTotal+start_fruit;
    }
};
// @lc code=end

