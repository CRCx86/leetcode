#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    bool lemonadeChange(std::vector<int> &bills)
    {
        int index = 0, five = 0, ten = 0;
        while (index < bills.size())
        {
            if (bills[index] == 5)
            {
                five++;
            }
            else if (bills[index] == 10)
            {
                if (five == 0)
                    return false;
                ten++;
                five--;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
            index++;
        }
        return true;

        // int index = 0;
        // std::map<int, int> charge;
        // while (index < bills.size())
        // {
        //     charge[bills[index]]++;

        //     while (bills[index] > 5 && (charge[10] > 0 || charge[5] > 0))
        //     {
        //         if (bills[index] <= 10)
        //         {
        //             if (charge[5])
        //             {
        //                 bills[index] -= 5;
        //                 charge[5]--;
        //             }
        //             else
        //             {
        //                 if (charge[10])
        //                 {
        //                     bills[index] -= 10;
        //                     charge[10]--;
        //                 }
        //             }
        //         }
        //         else if (bills[index] <= 20)
        //         {
        //             if (charge[10])
        //             {
        //                 bills[index] -= 10;
        //                 charge[10]--;
        //             }
        //             if (charge[5])
        //             {
        //                 bills[index] -= 5;
        //                 charge[5]--;
        //             }
        //         }
        //     }
        //     index++;
        // }

        // for (int i = 0; i < bills.size(); i++)
        // {
        //     if (bills[i] != 5)
        //     {
        //         return false;
        //     }
        // }

        // return true;
    }
};

int main()
{
    Solution solution;

    std::vector<int> v1 = {5, 5, 5, 10, 20};
    std::cout << (solution.lemonadeChange(v1) == true);

    std::vector<int> v2 = {5, 5, 10, 10, 20};
    std::cout << (solution.lemonadeChange(v2) == false);

    std::vector<int> v3 = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
    std::cout << (solution.lemonadeChange(v3) == true);

    std::vector<int> v4 = {5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
    std::cout << (solution.lemonadeChange(v4) == false);

    return 0;
}