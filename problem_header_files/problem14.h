#include <iostream>
#include <vector>
#include <numeric>

#define PROBLEM14 14

class EquilibriumIndex
{
private:
    std::vector<int> numbers;
public:
    EquilibriumIndex(std::vector<int> nums)
    {
        this -> numbers = nums;
    }

    void quadraticTimeSolution();
    void linearTimeSolution();
    void optimizedSolution1();
    void optimizedSolution2();
};

void EquilibriumIndex::quadraticTimeSolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();



    for (int i = 0; i < len; i++)
    {
        int left_index = 0;
        int right_index = len-1;

        int left_sum = 0;
        int right_sum = 0;
        while (left_index < i)
        {
            left_sum = left_sum + nums[left_index];
            left_index++;
        }

        while (right_index > i)
        {
            right_sum = right_sum + nums[right_index];
            right_index--;
        }

        if (right_sum == left_sum)
        {
            std::cout << i << " is an equilibrium index!" << std::endl;
        }

    }
}

void EquilibriumIndex::linearTimeSolution()
{
    int len = numbers.size();

    std::vector<int> left_sums;
    int left_sum = 0;
    left_sums.push_back(left_sum);

    for (int i = 1; i < len; i++)
    {
        left_sum = left_sum + numbers[i-1];
        left_sums.push_back(left_sum);
    }

    int right_sum = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (right_sum == left_sums[i])
            std::cout << i << " is an equilibrium index!" << std::endl;

        right_sum = right_sum + numbers[i];

    }
}

void EquilibriumIndex::optimizedSolution1()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum = sum + nums[i];

        nums[i] = sum;
    }

     if (nums[len-1]-nums[0] == 0)
        std::cout << "Equilibrium at 0!" << std::endl;

     for (int i = 1; i < len-1; i++)
     {
         if (nums[i-1] == nums[len-1] - nums[i])
         {
             std::cout << "Equilibrium at "  << i << "!" << std::endl;
         }

     }


     if (nums[len-2] == 0)
        std::cout << "Equilibrium at "  << len-1 << "!" << std::endl;


}

void EquilibriumIndex::optimizedSolution2()
{
    int len = numbers.size();

    int sum = accumulate(numbers.begin(), numbers.end(), 0);

    int right_sum = 0;

    for (int i = len-1; i >= 0; i--)
    {
        if (right_sum == sum - right_sum - numbers[i])
        {
            std::cout << "Equilibrium at "  << i << "!" << std::endl;
        }
        right_sum = right_sum + numbers[i];
    }


}
