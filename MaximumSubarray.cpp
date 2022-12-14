class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int _max = INT_MIN;
        int tmp_max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp_max = max(tmp_max + nums[i], nums[i]);
            _max = max(tmp_max, _max);
        }
        return _max;
    }
};

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int tmp_max = 1;
        int tmp_min = 1;
        int _max = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i] * tmp_max;
            int b = nums[i] * tmp_min;
            int c = nums[i];
            // tmp_max
            if (a >= b && a >= c)
            {
                tmp_max = a;
            }
            else if (b >= c && b >= a)
            {
                tmp_max = b;
            }
            else if (c >= a && c >= b)
            {
                tmp_max = c;
            }
            // tmp_min
            if (a <= b && a <= c)
            {
                tmp_min = a;
            }
            else if (b <= c && b <= a)
            {
                tmp_min = b;
            }
            else if (c <= a && c <= b)
            {
                tmp_min = c;
            }
            _max = max(_max, tmp_max);
        }

        return _max;
    }
};