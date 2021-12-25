#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    bool validPalindrome(std::string s)
    {
        int r = 0, l = s.length() - 1, count = 0;
        bool isPoly = true;
        while (r < l)
        {
            if (s[r] != s[l])
            {
                return ispoly(s, r + 1, l) || ispoly(s, r, l - 1);
            }
            else
            {
                r++;
                l--;
            }
        }

        return true;
    }

    bool ispoly(std::string s, int r, int l) {

        while (r < l)
        {
            if (s[r] != s[l])
            {
                return false;
            }
            else {
                r++;
                l--;
            }        
        }

        return true;
        
    }
};

int main()
{
    Solution solution;
    std::string s1 = "aba";
    std::cout << (solution.validPalindrome(s1) == true) << std::endl;
    std::string s2 = "abca";
    std::cout << (solution.validPalindrome(s2) == true) << std::endl;
    std::string s3 = "abc";
    std::cout << (solution.validPalindrome(s3) == false) << std::endl;
    std::string s4 = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    std::cout << (solution.validPalindrome(s4) == true) << std::endl;
    std::string s5 = "tebbem";
    std::cout << (solution.validPalindrome(s5) == false) << std::endl;
    // std::string s6 = "aguokepatgbnvfqmgmlcupuuffuupuculmgmqfvnbgtapekouga";
    std::string s6 = "gmlcupuuffuupuculmg"; // length =  19
    std::cout << (solution.validPalindrome(s6) == true) << std::endl;

    return 0;
}