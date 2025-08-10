/*
 * @lc app=leetcode id=3363 lang=cpp
 *
 * [3363] Find the Maximum Number of Fruits Collected
 */

#include<vector>
#include<array>
using namespace std;

// @lc code=start
class Solution {
public:
    // int corner_dp(const vector<vector<int>>& fruits, int i, int j, bool bl) {
    //     if (j == fruits.size()-2) return bl ? fruits[i][j] : fruits[j][i];
    //     // (1, 0), (2, 1), (3, 2)
    //     if (j==i-1) return corner_dp(fruits, i+1, j+1, bl) + (bl ? fruits[i][j] : fruits[j][i]);
    //     if (i == fruits.size()-1) return max(
    //         corner_dp(fruits, i, j+1, bl),
    //         j==i-2 ? -1 : corner_dp(fruits, i-1, j+1, bl)
    //     ) + (bl ? fruits[i][j] : fruits[j][i]);
    //     return max(
    //         corner_dp(fruits, i, j+1, bl),
    //         max(
    //             j==i-2 ? -1 : corner_dp(fruits, i-1, j+1, bl),
    //             corner_dp(fruits, i+1, j+1, bl)
    //         )
    //     ) + (bl ? fruits[i][j] : fruits[j][i]);
    // }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int diag = 0;
        const size_t n = fruits.size();
        for (int i = 0; i < n; ++i) diag += fruits[i][i];
        vector<vector<vector<int>>> corner_dp(n, vector<vector<int>>(n, vector<int>(2)));
        // 0 is bottom left, 1 is top right (opposite of recursive sol)
        corner_dp[n-1][n-2][0] = fruits[n-1][n-2];
        corner_dp[n-1][n-2][1] = fruits[n-2][n-1];
        for (int j = n-3; j >= 0; --j) {
            corner_dp[n-1][j][0] = max(
                corner_dp[n-1][j+1][0],
                j==n-3 ? -1 : corner_dp[n-2][j+1][0]
            ) + fruits[n-1][j];
            corner_dp[n-1][j][1] = max(
                corner_dp[n-1][j+1][1],
                j==n-3 ? -1 : corner_dp[n-2][j+1][1]
            ) + fruits[j][n-1];
            for (int i = n-2; i > j; --i) {
                corner_dp[i][j][0] = max(
                    corner_dp[i][j+1][0],
                    max(
                        j==i-2 ? -1 : corner_dp[i-1][j+1][0],
                        corner_dp[i+1][j+1][0]
                    )
                ) + fruits[i][j];
                corner_dp[i][j][1] = max(
                    corner_dp[i][j+1][1],
                    max(
                        j==i-2 ? -1 : corner_dp[i-1][j+1][1],
                        corner_dp[i+1][j+1][1]
                    )
                ) + fruits[j][i];
            }
        }
        return diag + corner_dp[n-1][0][0] + corner_dp[n-1][0][1];
    }
};
// @lc code=end

