/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string word) {
        bool consonant = false;
        bool vowel = false;
        int n = 0;
        for (char &x: word) {
            if (
                'a' <= x && x <= 'z' 
                || 'A' <= x && x <= 'Z'
            )
                switch (x) {
                    case 'a':
                        vowel = true;
                        break;
                    case 'e':
                        vowel = true;
                        break;
                    case 'i':
                        vowel = true;
                        break;
                    case 'o':
                        vowel = true;
                        break;
                    case 'u':
                        vowel = true;
                        break;
                    case 'A':
                        vowel = true;
                        break;
                    case 'E':
                        vowel = true;
                        break;
                    case 'I':
                        vowel = true;
                        break;
                    case 'O':
                        vowel = true;
                        break;
                    case 'U':
                        vowel = true;
                        break;
                    default:
                        consonant = true;
                }
            else if (x < '0' || x > '9')
                return false;
            n += 1;
        }
        return vowel && consonant && n >= 3;
    }
};
// @lc code=end

