class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n  = board.size() , m = board[0].size();

        auto dfs = [&](auto &dfs, int i,int j ,int idx, vector<vector<bool>>&visited)->bool{
            if(i<0 || i>=n || j<0 || j>=m) return false;

            if(word[idx] != board[i][j]) return false;

            if(visited[i][j]) return false;

            visited[i][j] = true;

            if(idx == word.size()-1){
               return true;
            }

            bool ans=dfs(dfs,i+1,j,idx+1,visited) ||
                    dfs(dfs,i,j+1,idx+1,visited) ||
                    dfs(dfs,i-1,j,idx+1,visited) ||
                    dfs(dfs,i,j-1,idx+1,visited);

            visited[i][j] = false;

            return ans;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s = "";
                vector<vector<bool>>visited(n,vector<bool>(m, false));

                if(dfs(dfs,i,j,0,visited)){
                    return true;
                }
            }
        }


        return false;


    }
};