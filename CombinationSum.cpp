
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0] == target;
        vector<vector<int> > vec(len, vector<int>(target + 1, 0));
        for (int i = 0; i <= target; i++)
        {
            if (i % nums[len - 1] == 0)
                vec[len - 1][i] = 1;
        }

        for (int i = len - 2; i >= 0; i--)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (j == 0)
                {
                    vec[i][j] = 1;
                    continue;
                }
                if (j < nums[i])
                {
                    vec[i][j] = vec[i + 1][j];
                }
                else if (j == nums[i])
                {
                    vec[i][j] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int tmp = 0, mul = 1; j - tmp >= 0; tmp += nums[i], mul++)
                    {
                        if (j - tmp == 0)
                        {
                            cnt++;
                            break;
                        }
                        cnt += vec[i + 1][j - tmp] * mul;
                    }
                    vec[i][j] = cnt;
                }
            }
        }
        return vec[0][target];
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int cnt = s.combinationSum4(nums, 4);
    cout << cnt << endl;

    return 0;
}