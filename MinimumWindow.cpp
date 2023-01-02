#include <iostream>
#include <string>
#include <array>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int lenS = s.length();
        int lenT = t.length();
        int resLen = INT_MAX;
        string res = "";

        // edge case
        if (lenS < lenT)
        {
            return "";
        }

        // idea: elongate the window until the window becomes valid, then narrow down the window as much as possible
        int l = 0;
        int r = 0;
        // a total of 128 chars
        int target[128] = {0};
        for (char &c : t)
        {
            target[c]++;
        }

        int mpp[128] = {0};
        bool gor = true;
        int have = 0;

        while (r < lenS && l <= r)
        {
            // if we are adding another target value to our map
            if (mpp[s[r]] < target[s[r]])
            {
                have++;
            }
            mpp[s[r]]++;

            // check if we already have the anagram
            bool containAnagram = true;
            if (r - l + 1 < lenT)
            {
                // if the window is smaller than the lenght of t
                containAnagram = false;
            }
            else if (have < lenT)
            {
                // if we do not have enough target values
                containAnagram = false;
            }
            else
            {
                for (char &c : t)
                {
                    if (mpp[c] < target[c])
                    {
                        containAnagram = false;
                        break;
                    }
                }
            }

            // if contain anagram
            if (containAnagram)
            {
                // update result
                int currLen = r - l + 1;
                if (currLen < resLen)
                {
                    resLen = currLen;
                    res = s.substr(l, currLen);
                }
                // narrow down to the next valid char
                while (target[s[l]] == 0 || mpp[s[l]] > target[s[l]])
                {
                    mpp[s[l]]--;
                    l++;
                }
                have--;
            }
            r++;
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str = "ADOBECODEBANC";
    string t = "ABC";
    cout << s.minWindow(str, t) << endl;

    return 0;
}