#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define PROBLEM1 1


class FindPairsOfSum
{
private:

    std::vector<int> numbers;
    int sum;

public:

    FindPairsOfSum(std::vector <int> nums, int desired_sum)
    {
        this -> numbers = nums;
        this -> sum = desired_sum;

    }
    FindPairsOfSum(){}

    void setNums(std::vector <int> nums)
    {
        this -> numbers = nums;
    }

    void setSum(int desired_sum)
    {
        this -> sum = desired_sum;
    }

    void bruteForceFind();
    void sortFind();
    void hashFind();


};

void FindPairsOfSum :: bruteForceFind()
{
    int len = numbers.size();
    bool found = false;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (numbers.at(i) + numbers.at(j) == sum)
            {
                std::cout << "Pair found (" << numbers[i] << ", " << numbers[j] << ")" << std::endl;
                found = true;
            }
        }
    }

    if (found == false)
        std::cout << "Pair not found!" << std::endl;

    return;
}

void FindPairsOfSum :: sortFind()
{
    std::vector<int> nums = numbers;
    sort(nums.begin(), nums.end());
    int len = nums.size();

    int low = 0;
    int high = len - 1;

    bool found = false;
    int my_sum;

    while (low < high)
    {
        my_sum = nums[low] + nums[high];
        if (my_sum == sum)
        {
            std::cout << "Pair found (" << nums[low] << ", " << nums[high] << ")" << std::endl;
            found = true;
            low++;
            high--;
        }
        else
            my_sum < sum ? low++ : high--;

    }

    if (found == false)
        std::cout << "Pair not found!" << std::endl;


}

void FindPairsOfSum :: hashFind()
{
    int len = numbers.size();

    std::unordered_map <int, int> sums;
    sums.insert({0,0});
    bool found = false;

    for (int i = 0; i < len; i++)
    {
        if (sums.find(sum-numbers[i]) != sums.end())
        {
            std::cout << "Pair found (" << numbers[sums[sum-numbers[i]]] << ", " << numbers[i] << ")" << std::endl;
            found = true;

        }
        else
        {
            sums.insert({numbers[i],i});
        }

    }
    if (found == false)
        std::cout << "Pair not found!" << std::endl;

}
