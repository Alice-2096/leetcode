#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        // iterate through s until the remaining substring.length() <= current longest string length

        int _max = 0;
        unordered_map<char, int> mpp; // use hash table to store the accessed values

        for (int i = 0; i < s.length(); i++)
        {
            if ((s.length() - i) <= _max)
            {
                break;
            }
            mpp.clear();
            int tmp = 0;
            for (int j = i; j < s.length(); j++)
            {
                // if not found
                if (mpp.find(s[j]) == mpp.end())
                {
                    mpp[s[j]] = 1; // insert key
                    tmp++;
                }
                else
                {
                    _max = max(tmp, _max);
                    break;
                }
            }
            _max = max(tmp, max);
        }

        return _max;
    }
};

int main()
{
    Solution s;
    string str = " ";
    cout << s.lengthOfLongestSubstring(str) << endl;

    return 0;
}
