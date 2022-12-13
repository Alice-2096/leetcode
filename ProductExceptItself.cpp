#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums;

        vector<int> res(nums.size(), 1);

        // store the prefix of each element in res;
        for (int i = 1; i < nums.size(); i++)
        {
            res[i] = nums[i - 1] * res[i - 1];
        }

        // get the postfix for each element, and multiply it with stored element to get the desired result
        int post = 1;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            res[j] *= post;
            post *= nums[j];
        }

        return res;
    }
};