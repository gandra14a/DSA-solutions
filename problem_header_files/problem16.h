#include <iostream>

#define PROBLEM16 16

class MajorityElement
{
private:
    int *numbers;

public:
    MajorityElement(int nums[], int len)
    {
        this -> numbers = new int[len];

        for (int i = 0; i < len; i++)
        {
            this -> numbers[i] = nums[i];
        }
    }


};
