#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);

    int output = s.maxProfit(nums);

    cout << output << endl;

    return 0;
}
