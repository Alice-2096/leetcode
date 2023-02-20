#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int> > &matrix, int k)
    {
        int len = matrix.size();
        int i;
        for (i = 1; i <= len; i++)
        {
            if (k <= i*i)
                break;
        }
        int cnt = (i-1)*(i-1) - k;
        int row = 0, col = 0, res;
        len = i;
        while (col < len && row < len && cnt > 0)
        {
            if (matrix[row][len - 1] <= matrix[len - 1][col])
            {
                res = matrix[row][len - 1];
                row++;
            }
            else
            {
                res = matrix[len - 1][col];
                col++;
            }
            cnt--;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a, b, c;
    vector<vector<int> > vec;
    a.push_back(1);
    a.push_back(5);
    a.push_back(9);
    b.push_back(10);
    b.push_back(11);
    b.push_back(13);
    c.push_back(12);
    c.push_back(13);
    c.push_back(15);
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    int target = 8;

    s.kthSmallest(vec, target);

    return 0;
}
