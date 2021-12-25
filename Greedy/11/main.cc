#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &height)
    {
        int result = 0;
        int length = height.size();
        int curr = 0;
        for (int i = 0; i < length; i++)
        {
            if (height[i] > curr)
            {
                curr = height[i];
                for (int j = length - 1; j > i; j--)
                {
                    result = std::max(result, std::min(curr, height[j]) * (j - i));
                }
                // int j = (length - 1) - i;
                // result = std::max(result, std::min(height[curr], height[j]) * (j - i));
            }

            // for (int j = i + 1; j < height.size(); j++)
            // {
            //     result = std::max(result, std::min(height[i], height[j]) * (j - i));
            // }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << solution.maxProfit(v1);
    std::vector<int> v2 = {1, 1};
    std::cout << solution.maxProfit(v2);
    return 0;
}