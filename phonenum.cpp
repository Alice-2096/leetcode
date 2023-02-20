#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    const unsigned int M = pow(10, 9) + 7;
    void dpf(string &pressedKeys, int curr, vector<int> &dp)
    {
        char t = pressedKeys[curr];
        int num;
        if (t == '7' || t == '9')
            num = 4;
        else
            num = 3;
        for (int i = curr; i < dp.size() && i - curr < num && pressedKeys[i] == t; i++)
        {
            if (i + 1 < dp.size())
                dp[curr] = (dp[curr] + dp[i + 1]) % M;
            else
                dp[curr] = (dp[curr] + 1) % M;
        }
    }
    int countTexts(string pressedKeys)
    {
        // dp
        int len = pressedKeys.length();
        vector<int> dp(len, 0);
        char l = pressedKeys[len - 1];
        dp[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--)
            dpf(pressedKeys, i, dp);
        return dp[0];
    }
};

int main()
{
    Solution s;
    string str = "22233";
    cout << s.countTexts(str);

    return 0;
}
