
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int cnt = 0;
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int> > vec(len2, vector<int>(len1, 0));
        if (text1.find(text2.substr(0, 1)) != string::npos)
        {
            for (auto i : vec[0])
                i = 1;
        }
        if (text2.find(text1.substr(0, 1)) != string::npos)
        {
            for (auto i : vec)
                i[0] = 1;
        }
        for (int i = 1; i < len2; i++)
        {
            for (int j = 1; j < len1; j++)
            {
                if (text1[j] == text2[i])
                {
                    vec[i][j] = vec[i - 1][j - 1] + 1; // recurrence relation
                }
                else
                {
                    vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]); // recurrence relation
                }
            }
        }

        return vec[len2 - 1][len1 - 1];
    }
};

int main()
{
    Solution s;
    string s1 = "abc";
    string s2 = "abc";
    int cnt = s.longestCommonSubsequence(s1, s2);
    cout << cnt << endl;

    return 0;
}
