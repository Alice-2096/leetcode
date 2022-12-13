#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> v = nums;
//         sort(v.begin(), v.end());
//         vector<int> ret;
//         int last = v[v.size() - 1];
//         for (int i = 0; i < v.size(); i++)
//         {
//             if (v[i] + last < target)
//             {
//                 continue;
//             }
//             for (int j = i; j < v.size(); j++)
//             {
//                 if (v[i] + v[j] == target)
//                 {
//                     // find the original indices
//                     int a = v[i];
//                     int b = v[j];
//                     v = nums;
//                     for (int k = 0; k < v.size(); k++)
//                     {
//                         if (v[k] == a)
//                         {
//                             ret.push_back(k);
//                             for (int g = k + 1; g < v.size(); g++)
//                             {
//                                 if (v[g] == b)
//                                 {
//                                     ret.push_back(g);
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return ret;
//     }
// };

// Official Solution
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> visited;
        for (int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];
            if (visited.find(need) != visited.end())
            {
                return {visited[need], i};
            }
            visited[nums[i]] = i; // push the pair <nums[index], index> into map
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(-5);
    nums.push_back(-4);
    nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(-1);

    int target = -8;

    vector<int> ret = s.twoSum(nums, target);

    cout << ret[0] << ", " << ret[1] << endl;

    return 0;
}
