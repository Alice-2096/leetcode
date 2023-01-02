#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs_pacific(int r, int c, vector<vector<int>> &heights, vector<vector<int>> &pacific, vector<vector<int>> &visited)
    {
        if (r == 0 || c == 0)
        {
            visited[r][c] = 1;
            pacific[r][c] = 1;
            return;
        }
        // flow up
        if (r - 1 >= 0)
        {
            if (heights[r - 1][c] < heights[r][c])
            {
                if (!visited[r - 1][c])
                    dfs_pacific(r - 1, c, heights, pacific, visited);
                if (pacific[r - 1][c])
                    pacific[r][c] = 1;
                return;
            }
        }
        // flow left
        if (c - 1 >= 0)
        {
            if (heights[r][c - 1] < heights[r][c])
            {
                if (!visited[r][c - 1])
                    dfs_pacific(r, c - 1, heights, pacific, visited);
                if (pacific[r][c - 1])
                    pacific[r][c] = 1;
                return;
            }
        }
    }

    void dfs_atlantic(int r, int c, vector<vector<int>> &heights, vector<vector<int>> &atlantic, vector<vector<int>> &visited)
    {
        int rowNum = heights.size();
        int colNum = heights[0].size();
        if (r == rowNum - 1 || c == colNum - 1)
        {
            visited[r][c] = 1;
            atlantic[r][c] = 1;
            return;
        }
        // flow downward
        if (r + 1 <= rowNum)
        {
            if (heights[r + 1][c] < heights[r][c])
            {
                if (!visited[r + 1][c])
                    dfs_atlantic(r + 1, c, heights, atlantic, visited);
                if (atlantic[r + 1][c])
                    atlantic[r][c] = 1;
                return;
            }
        }
        // flow right
        if (c + 1 <= colNum)
        {
            if (heights[r][c + 1] < heights[r][c])
            {
                if (!visited[r][c + 1])
                    dfs_atlantic(r, c + 1, heights, atlantic, visited);
                if (atlantic[r][c + 1])
                    atlantic[r][c] = 1;
                return;
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rowNum = heights.size();
        int colNum = heights[0].size();
        if (rowNum == colNum == 1)
            return {{0, 0}};

        vector<vector<int>> res;
        vector<vector<int>> visited(rowNum, vector<int>(colNum, 0));
        vector<vector<int>> pacific(rowNum, vector<int>(colNum, 0));
        vector<vector<int>> atlantic(rowNum, vector<int>(colNum, 0));

        for (int r = 0; r < rowNum; r++)
        {
            for (int c = 0; c < colNum; c++)
            {
                if (visited[r][c])
                {
                    continue;
                }
                dfs_pacific(r, c, heights, pacific, visited);
            }
        }
        visited.clear();

        for (int r = 0; r < rowNum; r++)
        {
            for (int c = 0; c < colNum; c++)
            {
                if (visited[r][c])
                {
                    continue;
                }
                dfs_atlantic(r, c, heights, atlantic, visited);
            }
        }

        for (int r = 0; r < rowNum; r++)
        {
            for (int c = 0; c < colNum; c++)
            {
                if (atlantic[r][c] && pacific[r][c])
                    res.push_back({r, c});
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> height = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> vec = s.pacificAtlantic(height);

    for (auto &v : vec)
    {
        cout << "{" << v[0] << ", " << v[1] << "}" << endl;
    }

    return 0;
}
