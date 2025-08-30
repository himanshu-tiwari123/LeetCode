class Solution {
    const int MOD = 1e9 + 7;
    int n, m;
    vector<vector<int>> dp;

    // Directions: 0 = right, 1 = down
    pair<int,int> simulate(int i, int j, int dir, vector<vector<int>>& grid) {
        while (true) {
            if (i < 0 || j < 0 || i >= n || j >= m) return {-1,-1}; // out of bounds
            if (i == n-1 && j == m-1) return {i,j}; // reached destination

            if (grid[i][j] == 0) {
                // Landed on empty cell → stop simulation
                return {i,j};
            }

            // Reflect depending on entry direction
            if (dir == 0) { // came moving right → reflect downward
                i++;
                dir = 1;
            } else {        // came moving down → reflect rightward
                j++;
                dir = 0;
            }
        }
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (i == n-1 && j == m-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        long long res = 0;

        // Try moving right
        if (j+1 < m) {
            auto [ni, nj] = simulate(i, j+1, 0, grid); 
            if (ni != -1) {
                if (ni == n-1 && nj == m-1) res++;
                else res += dfs(ni, nj, grid);
            }
        }

        // Try moving down
        if (i+1 < n) {
            auto [ni, nj] = simulate(i+1, j, 1, grid); 
            if (ni != -1) {
                if (ni == n-1 && nj == m-1) res++;
                else res += dfs(ni, nj, grid);
            }
        }

        return dp[i][j] = res % MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        return dfs(0, 0, grid);
    }
};