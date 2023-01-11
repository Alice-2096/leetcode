#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int start, int len)
    {
        vector<int> dp(len, 0);

        if (len < 0)
            return 0;
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[start];
        dp[len - 1] = nums[start + len - 1];
        dp[len - 2] = max(nums[start + len - 1], nums[start + len - 2]);

        for (int i = start + len - 3, ind = len - 3; i >= start && ind >= 0; i--, ind--)
        {
            // recurrence relation:
            if (dp[ind + 1] >= (dp[ind + 2] + nums[i]))
                dp[ind] = dp[ind + 1];
            else
                dp[ind] = nums[i] + dp[ind + 2];
        }

        return dp[0];
    }

    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[1], nums[0]);
        if (len == 3)
            return max(nums[0], max(nums[1], nums[2]));

        int case1 = helper(nums, 1, len - 1);
        int case2 = nums[0] + helper(nums, 2, len - 3);

        return max(case1, case2);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(100);
    int cnt = s.rob(nums);
    cout << cnt << endl;

    return 0;
}
