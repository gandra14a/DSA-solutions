#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>

#define PROBLEM7 7


class MaximumProduct
{
private:
    std::vector<int> numbers;
public:
    MaximumProduct(std::vector<int> nums)
    {
        this->numbers = nums;
    }
    MaximumProduct(){}

    void setNumbers(std::vector<int> nums)
    {
        this->numbers = nums;
    }

    void bruteForceSolution();
    void sortSolution();
    void linearTimeSolution();
};

void MaximumProduct::bruteForceSolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    if (len < 2)
    {
        std::cout << "Only one element!" << std::endl;
        return;
    }
    std::unordered_map<int,std::vector<std::pair<int,int>>> all_product_pairs;
    std::pair<int,int> any_pair;

    int max_product = nums[0] * nums[1];
    //int max_product1 = INT_MIN;
    int product;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            product = nums[i] * nums[j];
            any_pair.first  = nums[i];
            any_pair.second = nums[j];

            all_product_pairs[product].push_back(any_pair);
            if (product >= max_product)
            {
                max_product = product;
            }
        }
    }
    for (std::pair<int,int> max_pair : all_product_pairs[max_product])
    {
        std::cout << "(" << max_pair.first << ", " << max_pair.second << ")" << std::endl;
    }

}

void MaximumProduct::sortSolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();


    std::pair<int,int> max_pair_beg;
    std::pair<int,int> max_pair_end;




    sort(nums.begin(), nums.end());

    int low = nums[0] * nums[1];
    int high = nums[len-1] * nums[len-2];

    if (low < high)
    {
        int first = nums[len-1];
        int second = nums[len-2];

        max_pair_end.first = first;
        max_pair_end.second = second;

        std::cout << "(" << max_pair_end.first << ", " << max_pair_end.second << ")" << std::endl;

    }
    else if (low > high)
    {
        int first = nums[0];
        int second = nums[1];

        max_pair_beg.first = first;
        max_pair_beg.second = second;

        std::cout << "(" << max_pair_beg.first << ", " << max_pair_beg.second << ")" << std::endl;
    }
    else
    {
        max_pair_beg.first = nums[0];
        max_pair_beg.second = nums[1];
        max_pair_end.first = nums[len-2];
        max_pair_end.second = nums[len-1];

        std::cout << "(" << max_pair_beg.first << ", " << max_pair_beg.second << ")" << std::endl;
        std::cout << "(" << max_pair_end.first << ", " << max_pair_end.second << ")" << std::endl;
    }


}

void MaximumProduct::linearTimeSolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    int min1 = nums[0];
    int max1 = nums[0];
    int min2 = INT_MAX;
    int max2 = INT_MIN;

    for (int i = 1; i<len; i++)
    {
        if (nums[i] < min1)
        {
            min2 = min1;
            min1 = nums[i];

        }
        else if (nums[i] < min2)
        {
            min2 = nums[i];
        }


        if (nums[i] > max1)
        {
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] > max2)
        {
            max2 = nums[i];

        }
    }
    max1*max2 > min1*min2 ? std::cout << "(" << max1 << ", " << max2 << ")" << std::endl :
            std::cout << "(" << min1 << ", " << min2 << ")" << std::endl;
}


