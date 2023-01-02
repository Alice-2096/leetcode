#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    int ROW; 
    int COL; 
    //return true if the path contains unvisited '1'. return false otherwise 
    bool dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited){
        if (r < 0 || c < 0 || r >= ROW || c >= COL) return false; 
        if (grid[r][c] == 0) return false; 
        if (visited[r][c]) return false; 

        visited[r][c] = 1; 
        dfs(r + 1, c, grid, visited); 
        dfs(r - 1, c, grid, visited); 
        dfs(r, c + 1, grid, visited); 
        dfs(r, c - 1, grid, visited); 
        return true; 
    }

    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size();
        COL = grid[0].size(); 
        vector<vector<int>> visited(ROW, vector<int>(COL, 0)); 
        bool flag; 
        int numIsland = 0; 
        
        for (int r = 0; r < ROW; r++){
            for (int c = 0; c < COL; c++){
                flag = false; 
                if (!visited[r][c]) flag = dfs(r, c, grid, visited);
                if (flag) numIsland++; 
            }
        }

        return numIsland; 
    }
};