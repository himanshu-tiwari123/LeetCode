class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();

        bool isPossible = false;

        auto dfs = [&](auto &dfs,int i,int j, string s,vector<vector<bool>>&visited)->void{
            if(i>=n || i<0 || j <0 || j>=m){
                return ;
            }

            if(visited[i][j]) return;
            if(word[s.size()] != board[i][j]) return;

            s += board[i][j];

            visited[i][j] = true;
            
            if(s == word){
               isPossible = true;
               return;
            }

            dfs(dfs, i,j+1,s, visited);

            dfs(dfs, i+1,j, s, visited);

            dfs(dfs, i-1, j, s, visited);

            dfs(dfs, i, j-1, s, visited);

            if(!s.empty()){
                s.pop_back();
            }

            visited[i][j] = false;

        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s= "";
                vector<vector<bool>>visited(n,vector<bool>(m, false));
                dfs(dfs,i,j,s, visited);

            }
        }
        

        return isPossible;
    }
};