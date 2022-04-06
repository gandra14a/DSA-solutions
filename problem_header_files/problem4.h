#include <iostream>
#include <vector>

#define PROBLEM4 4

class SortBinaryArrayInLinearTime
{
private:
    std::vector<int> numbers;

    void swapNums(std::vector<int> &nums, int k, int l)
    {
        int temp = nums[k];
        nums[k] = nums[l];
        nums[l] = temp;
    }

public:
    SortBinaryArrayInLinearTime(std::vector<int> nums)
    {
        this -> numbers = nums;
    }

    SortBinaryArrayInLinearTime(){}

    void setNumbers(std::vector<int> nums)
    {
        this -> numbers = nums;
    }

    void mySolution();
    void countZerosSolution();
    void solution3();
    void pivotSolution();
};


void SortBinaryArrayInLinearTime :: mySolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    int low = 0;
    int high = len - 1;

    while (low < high)
    {
        while (nums[low] == 0)
            low++;
        while (nums[high] == 1)
            high--;
        if (low < high)
        {
            nums[low] = 0;
            nums[high] = 1;
            low++;
            high--;
        }
    }

    std::cout << "{";
    for (int i = 0; i < len ; i++)
    {
        std::cout << " " << nums[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void SortBinaryArrayInLinearTime :: countZerosSolution()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    int zeros = 0;

    for (int i = 0; i < len; i++)
    {
        nums[i] == 0 ? zeros++ : zeros += 0;
    }

    int k = 0;
    while (k < zeros)
        nums[k++] = 0;

    while (k < len)
        nums[k++] = 1;

    std::cout << "{";
    for (int i = 0; i < len ; i++)
    {
        std::cout << " " << nums[i] << " ";
    }
    std::cout << "}" << std::endl;

}

void SortBinaryArrayInLinearTime :: solution3()
{
    std::vector<int> nums = numbers;
    int len = nums.size();

    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] == 0)
        {
            nums[k] = 0;
            k++;
        }
    }
    while (k < len)
    {
        nums[k] = 1;
        k++;
    }

    std::cout << "{";
    for (int i = 0; i < len ; i++)
    {
        std::cout << " " << nums[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void SortBinaryArrayInLinearTime::pivotSolution()
{

    std::vector<int> nums = numbers;
    int len = nums.size();

    int pivot = 1;
    int m = 0;

    for (int i = 0; i < len; i++)
    {
        if (nums[i] < pivot)
        {
            swapNums(nums, i, m);
            m++;
        }
    }

    std::cout << "{";
    for (int i = 0; i < len ; i++)
    {
        std::cout << " " << nums[i] << " ";
    }
    std::cout << "}" << std::endl;


}
