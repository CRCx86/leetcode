#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int profit = 0;
        int length = prices.size();
        for (int i = 0; i < length - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};

int main()
{
    Solution solution;
    std::vector<int> v1 = {7, 1, 5, 3, 6, 4};
    std::cout << solution.maxProfit(v1);
    std::vector<int> v2 = {1,2,3,4,5};
    std::cout << solution.maxProfit(v2);
    std::vector<int> v3 = {7,6,4,3,1};
    std::cout << solution.maxProfit(v3);
    return 0;
}