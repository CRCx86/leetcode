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

    int largestSumAfterKNegations(std::vector<int> &nums, int k)
    {
        int result = 0, index = 0;
        std::sort(nums.begin(), nums.end());

        while (k > 0)
        {
            if (index >= nums.size() - 1)
            {
                index = 0;
                std::sort(nums.begin(), nums.end());
            }

            if (nums[index] != 0)
            {
                nums[index] = -nums[index];
                if (nums.size() > 1 && nums[index] > nums[index + 1])
                    index++;
            }
            k--;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            result += nums[i];
        }

        return result;
    }

    int largestSumAfterKNegations(int nums[], int k)
    {
        int result = 0, index = 0;        
        int n = sizeof(nums) / sizeof(nums[0]);
        std::sort(nums, nums + n);

        while (k > 0)
        {
            if (index > n - 1)
            {
                index = 0;
                std::sort(nums, nums + n);
            }

            if (nums[index] != 0)
            {
                nums[index] = -nums[index];
                if (n > 1 && nums[index] > nums[index + 1])
                    index++;
            }
            k--;
        }

        for (int i = 0; i < n; i++)
        {
            result += nums[i];
        }

        return result;
    }
};

int main()
{
    Solution *solution = new Solution();

    std::vector<int> v1 = {4, 2, 3};
    int k1 = 1;
    std::cout << (solution->largestSumAfterKNegations(v1, k1) == 5) << std::endl;

    std::vector<int> v2 = {3, -1, 0, 2};
    int k2 = 3;
    std::cout << (solution->largestSumAfterKNegations(v2, k2) == 6) << std::endl;

    std::vector<int> v3 = {2, -3, -1, 5, -4};
    int k3 = 2;
    std::cout << (solution->largestSumAfterKNegations(v3, k3) == 13) << std::endl;

    std::vector<int> v4 = {-2, 9, 9, 8, 4};
    int k4 = 5;
    std::cout << (solution->largestSumAfterKNegations(v4, k4) == 32) << std::endl;

    std::vector<int> v5 = {-4, -2, -3};
    int k5 = 4;
    std::cout << (solution->largestSumAfterKNegations(v5, k5) == 0) << std::endl;

    std::vector<int> v6 = {-6, -8, -7, 1};
    int k6 = 4;
    std::cout << (solution->largestSumAfterKNegations(v6, k6) == 0) << std::endl;

    int v7[]= {-6, -8, -7, 1};
    std::cout << (solution->largestSumAfterKNegations(v7, k6) == 0) << std::endl;

    delete solution;

    return 0;
}