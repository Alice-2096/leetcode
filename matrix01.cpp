#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> mat(R, vector<int>(C, 0));

        for (int r = 0; r < R; r++)
        {
            for (int c = C - 1; c >= 0; c--)
            {
                if (c = C - 1)
                {
                    mat[r][c] = (int)(matrix[r][c] - '0');
                    continue;
                }
                if (matrix[r][c] == '0')
                    mat[r][c] = 0;
                else
                    mat[r][c] = mat[r][c + 1] + 1;
            }
        }

        int res = 0;
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (mat[r][c] == 0)
                    continue;
                if (mat[r][c] == 1)
                {
                    res = max(res, 1);
                    continue;
                }
                int len = mat[r][c];
                if (len + r - 1 >= R)
                    continue;
                bool flag = true;
                int row = r + 1;
                while (row <= len + r - 1)
                {
                    if (mat[row][c] != len)
                    {
                        flag = false;
                        break;
                    }
                    row++;
                }
                if (flag)
                    res = max(res, len * len);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> vec;
    vector<char> v, e;
    v = {1, 1, 1, 1, 0};
    vec.push_back(v);
    vec.push_back(e);
    s.maximalSquare(vec);

    return 0;
}
