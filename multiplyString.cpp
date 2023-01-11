#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int ret = 0;
        for (int i = num2.length() - 1, tens = 1; i >= 0; i--, tens *= 10)
        {
            int carry = 0;
            int res = 0;
            for (int j = num1.length() - 1, ten = tens; j >= 0; j--, ten *= 10)
            {
                int mul = (int)(num1[j] - '0') * (num2[i] - '0') + carry;
                res += (mul % 10) * ten;
                carry = mul / 10;
                if (j == 0)
                {
                    res += carry * ten * 10;
                }
            }
            ret += res;
        }

        // O(len1 * len2)

        return to_string(ret);
    }
};

int main()
{
    Solution s;
    string a = "123";
    string b = "456";
    string res = s.multiply(a, b);
    cout << res;
    return 0;
}