/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    pair<int, unordered_map<int, int>> numToDigitMap(int n) {
        unordered_map<int, int> digit_map;
        int num_digits = 0;
        while (n > 0) {
            ++digit_map[n % 10];
            n /= 10;
            ++num_digits;
        }
        return {num_digits, digit_map};
    }

    int allNines(int numDigits) {
        if (numDigits == 10) return INT32_MAX / 2 + 1;
        int n = 9;
        while (numDigits > 1) {
            n = n*10 + 9;
            --numDigits;
        }
        return n;
    }

    bool reorderedPowerOf2(int n) {
        auto [n_digits, n_digit_map] = numToDigitMap(n);
        int all9s = allNines(n_digits);
        for (int pow2 = 1; pow2 < all9s; pow2 *= 2) {
            auto [_, pow2_digit_map] = numToDigitMap(pow2);
            if (pow2_digit_map == n_digit_map) return true;
        }
        return false;
    }
};
// @lc code=end

