#include <iostream>
#include <vector>
#include <map>
#include <set>

class Solution
{
public:
    int longestPalindrome(std::string s)
    {
        std::map<short, short> m;
        for (auto c : s)
        {
            m[c] += 1;
        }

        short result = 0;
        // for (auto e : m)
        // {
        //     result += e.second / 2 * 2;
        //     if (result % 2 == 0 && e.second % 2 == 1)
        //     {
        //         result++;
        //     }
        // }

        bool hasOne = false;
        for (auto e : m)
        {
            if (e.second == 1)
                hasOne = true;
            if (e.second > 1 && e.second % 2 == 0)
            {
                result += e.second;
            } else {
                result += e.second - 1;
                hasOne = true;
            }
        }

        if (hasOne)
        {
            result++;
        }        

        return result;
    }
};

int main()
{
    Solution solution;
    std::string s1 = "abccccdd";
    std::cout << (solution.longestPalindrome(s1) == 7) << std::endl;
    std::string s2 = "a";
    std::cout << (solution.longestPalindrome(s2) == 1) << std::endl;
    std::string s3 = "bb";
    std::cout << (solution.longestPalindrome(s3) == 2) << std::endl;
    std::string s4 = "ccc";
    std::cout << (solution.longestPalindrome(s4) == 3) << std::endl;
    std::string s5 = "bananas";
    std::cout << (solution.longestPalindrome(s5) == 5) << std::endl;
    std::string s6 = "abcba";
    std::cout << (solution.longestPalindrome(s6) == 5) << std::endl;
    return 0;
}