class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> tmp;
        int a;

        for (int i = 0; i < nums.size(); i++)
        {
            // skip over duplicates of a
            if (i != 0 && a == nums[i])
            {
                continue;
            }

            a = nums[i];
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    tmp = {nums[i], nums[front], nums[back]};
                    ans.push_back(tmp);

                    // skip over duplicate of 'front'
                    while (front < back && nums[front] == tmp[1])
                        front++;

                    // skip over duplicate of 'back'
                    while (front < back && nums[back] == tmp[2])
                        back--;
                }
            }
        }
        return ans;
    }
};