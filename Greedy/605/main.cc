#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {

        int i = 0;
        while (i < flowerbed.size() && n > 0)
        {
            if (flowerbed.size() == 1 && flowerbed[i] == 0)
            {
                n--;
                flowerbed[i++] = 1;
                i++;
            }
            else if (i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                n--;
                flowerbed[i++] = 1;
                i++;
            }
            else if (i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                n--;
                flowerbed[i++] = 1;
                i++;
            }
            else if (i > 0 && i < flowerbed.size() && flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                n--;
                flowerbed[i++] = 1;
                i++;
            }
            else
            {
                i++;
            }

            if (n == 0)
            {
                return true;
            }
            
        }
        return n == 0;
    }
};

int main()
{
    Solution solution;
    std::vector<int> v1 = {1, 0, 0, 0, 1};
    std::cout << (solution.canPlaceFlowers(v1, 1) == true) << std::endl;
    std::vector<int> v2 = {1, 0, 0, 0, 1};
    std::cout << (solution.canPlaceFlowers(v2, 2) == false) << std::endl;
    std::vector<int> v3 = {0, 0, 1, 0, 1};
    std::cout << (solution.canPlaceFlowers(v3, 1) == true) << std::endl;
    std::vector<int> v4 = {0};
    std::cout << (solution.canPlaceFlowers(v4, 1) == true) << std::endl;
    std::vector<int> v5 = {0, 0, 1, 0, 0};
    std::cout << (solution.canPlaceFlowers(v5, 1) == true) << std::endl;
    // std::vector<int> v5 = {1, 2, 3}, v6 = {3};
    // std::cout << (solution.findContentChildren(v5, v6) == 1) << std::endl;

    return 0;
}