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

    int largestPerimeter(std::vector<int> &nums)
    {
        int result = 0, index = nums.size() - 1;
        std::sort(nums.begin(), nums.end());

        // моё решение
        // while (index - 2 >= 0)
        // {
        //     if (nums[index - 1] + nums[index - 2] <= nums[index])
        //     {
        //         index--;
        //         continue;
        //     }

        //     result = std::max(result, nums[index - 1] + nums[index - 2] + nums[index]);

        //     index--;
        // }

        while (index - 2 >= 0)
        {            
            if (nums[index - 1] + nums[index - 2] > nums[index])
            {
                return std::max(result, nums[index - 1] + nums[index - 2] + nums[index]);
            }

            index--;
        }

        return result;
    }
};

int main()
{
    Solution *solution = new Solution();

    std::vector<int> v1 = {2, 1, 2};
    std::cout << (solution->largestPerimeter(v1) == 5) << std::endl;

    std::vector<int> v2 = {1, 2, 1};
    std::cout << (solution->largestPerimeter(v2) == 0) << std::endl;

    std::vector<int> v3 = {3, 2, 3, 4};
    std::cout << (solution->largestPerimeter(v3) == 10) << std::endl;

    std::vector<int> v4 = {3, 6, 2, 3};
    std::cout << (solution->largestPerimeter(v4) == 8) << std::endl;

    delete solution;

    return 0;
}