/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
public:
    double soupServingsRecursive(int a, int b) {
        double sum = 0;

        if (a <= 100) sum += 0.25;
        else sum += 0.25*soupServingsRecursive(a-100, b);

        if (a <= 75 && b <= 25) sum += 0.125;
        else if (a <= 75) sum += 0.25;
        else if (b <= 25) sum += 0;
        else sum += 0.25*soupServingsRecursive(a-75, b-25);

        if (a <= 50 && b <= 50) sum += 0.125;
        else if (a <= 50) sum += 0.25;
        else if (b <= 50) sum += 0;
        else sum += 0.25*soupServingsRecursive(a-50,b-50);

        if (a <= 25 && b <= 75) sum += 0.125;
        else if (a <= 25) sum += 0.25;
        else if (b <= 75) sum += 0;
        else sum += 0.25*soupServingsRecursive(a-25,b-75);

        return sum;
    }

    double soupServings(int n) {
        if (n == 0) return 0.5;
        return soupServingsRecursive(n, n);
    }
};
// @lc code=end

