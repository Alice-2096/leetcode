
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
private:
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> vec(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            vec[s[i] - 'a']++;
        }
        string res = "";
        int _min;

        for (int i = 0; i < s.length(); i++)
        {
            _min = 27;
            for (int j = i; j < s.length(); j++)
            {
                _min = min(_min, s[j] - 'a');
            }

            if (vec[s[i] - 'a'] == 1)
            {
                res += s[i];
                vec[s[i] - 'a'] = 0;
            }
            else if (vec[s[i] - 'a'] > 1)
            {
                if (s[i] - 'a' == _min)
                {
                    res += s[i];
                    vec[s[i] - 'a'] = 0;
                }
                else
                {
                    vec[s[i] - 'a']--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "ecbacba";
    string res = s.removeDuplicateLetters(str);
    cout << res << endl;

    return 0;
}