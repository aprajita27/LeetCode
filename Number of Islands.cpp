//https://leetcode.com/problems/number-of-islands/
//TC: O(MN) M: number of rows N: number of columns
class Solution {
public:
    bool isValid (vector<vector<char>>& grid, int row, int col) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1';
    }
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void dfs (vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        visited[row][col] = true; //step 1
        for (int i = 0; i < dr.size(); ++i) { //step 2
            int new_r = row + dr[i];
            int new_c = col + dc[i];
            if (!isValid(grid, new_r, new_c) || visited[new_r][new_c]) //step 2a
                continue;   
            dfs(grid, new_r, new_c, visited); //step 2b
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int count = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited;
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j, visited);
                    count += 1;
                }
            }
        }
        return count;
    }
};
