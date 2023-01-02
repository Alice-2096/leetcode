#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // O(n)
        int i = 0;
        while (i < s.length())
        {
            if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z'))
            {
                s.erase(i, 1); // erase 1 char at index i
                continue;
            }
            s[i] = tolower(s[i]);
            i++;
        }

        // O(n)
        int left = 0;
        int right = s.length() - 1;
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str = "0P";
    cout << s.isPalindrome(str) << endl;

    return 0;
}
