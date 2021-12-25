#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    Solution()
    {
        std::cout << "Consturctor" << std::endl;
    }

    ~Solution()
    {
        std::cout << "~ Deconsturctor" << std::endl;
    }

    std::vector<int> diStringMatch(std::string s)
    {
        int index = 0, i = 0, d = s.length();
        std::vector<int> v;
        while (index < s.length())
        {
            if (s[index] == 'I')
            {
                v.push_back(i);
                i++;
            }
            else
            {
                v.push_back(d);
                d--;
            }

            index++;
        }

         v.push_back(i);

        return v;
    }
};

int main()
{
    Solution *solution = new Solution();

    std::string s1 = "IDID";
    std::cout << solution->diStringMatch(s1).size() << std::endl;

    std::string s2 = "III";
    std::cout << solution->diStringMatch(s2).size() << std::endl;

    std::string s3 = "DDI";
    std::cout << solution->diStringMatch(s3).size() << std::endl;

    std::string s4 = "IDD";
    std::cout << solution->diStringMatch(s4).size() << std::endl;

    std::string s5 = "IID";
    std::cout << solution->diStringMatch(s5).size() << std::endl;

    delete solution;

    return 0;
}