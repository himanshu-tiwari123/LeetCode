class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int dim = 1 << N; // Same as 2^N
        vector<vector<int>> grid(dim, vector<int>(dim));

        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                int val = 0;
                // Iterate through each level of the quadtree, from the smallest (k=0)
                // up to the largest (k=N-1).
                for (int k = 0; k < N; ++k) {
                    int bit_i = (i >> k) & 1; // k-th bit of i
                    int bit_j = (j >> k) & 1; // k-th bit of j
                    
                    int quadrant_val;
                    if (bit_i == 0 && bit_j == 0) { // Top-Left
                        quadrant_val = 3;
                    } else if (bit_i == 0 && bit_j == 1) { // Top-Right
                        quadrant_val = 0;
                    } else if (bit_i == 1 && bit_j == 0) { // Bottom-Left
                        quadrant_val = 2;
                    } else { // Bottom-Right (bit_i=1, bit_j=1)
                        quadrant_val = 1;
                    }
                    
                    // Add the quadrant's value, scaled by its level.
                    // 1 << (2 * k) is the same as 4^k.
                    val += quadrant_val * (1 << (2 * k));
                }
                grid[i][j] = val;
            }
        }
        return grid;
    }
};