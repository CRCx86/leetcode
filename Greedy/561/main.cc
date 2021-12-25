#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    int arrayPairSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int i = 0, result = 0;
        while (i < nums.size())
        {
            if (i > 0 && i % 2 != 0)
            {
                result += std::min(nums[i - 1], nums[i]);
                i++;
            } else {
                i++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> v1 = {1, 4, 3, 2};
    std::cout << (solution.arrayPairSum(v1) == 4) << std::endl;
    std::vector<int> v2 = {6,2,6,5,1,2};
    std::cout << (solution.arrayPairSum(v2) == 9) << std::endl;
    // std::vector<int> v5 = {1, 2, 3}, v6 = {3};
    // std::cout << (solution.findContentChildren(v5, v6) == 1) << std::endl;

    return 0;
}