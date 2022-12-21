#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // use a stack
        stack<char> stk;
        for (char &c : s)
        {
            switch (c)
            {
            case '(':
                stk.push(c);
            case '{':
                stk.push(c);
            case '[':
                stk.push(c);
            case ')':
                if (stk.top() == '(')
                    stk.pop();
                else
                    return false;
            case '}':
                if (stk.top() == '{')
                    stk.pop();
                else
                    return false;
            case ']':
                if (stk.top() == '[')
                    stk.pop();
                else
                    return false;
            default:
                break;
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    string str = "()[]{}";
    cout << s.isValid(str) << endl;

    return 0;
}