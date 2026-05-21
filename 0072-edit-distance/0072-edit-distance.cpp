class Solution {
    vector<vector<int>>dp;

    int findAns(int i,int j,string &s1, string &s2){
        //Base Case:
        if(i<0 ) return j+1;

        if(j<0) return i+1;


        if(dp[i][j] != -1){
            return dp[i][j];
        }


        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + findAns(i-1,j-1,s1,s2);
        }


        //3 parts: 
        
        // return dp[i][j] = 1 + min({findAns(i,j-1,s1,s2) ,findAns(i-1,j,s1,s2),findAns(i-1,j-1,s1,s2) });

        int insert = 1 + findAns(i,j-1,s1,s2);

        int remove = 1 + findAns(i-1,j,s1,s2);

        int replace = 1 + findAns(i-1,j-1,s1,s2);


        return dp[i][j] = min({insert,remove,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();

    //     dp.assign(n+1,vector<int>(m+1,-1));
    //    //Using memoization:
    //     return findAns(n-1,m-1,word1,word2);

        //Using Tabulation;
        dp.assign(n+1,vector<int>(m+1,0));

        //Base case is if(i==0) return j || if(j==0) return 1;
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int insert = 1 + dp[i][j-1];

                    int remove = 1 + dp[i-1][j];

                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insert,remove,replace});
                }
            }
        }

        return dp[n][m];



    }
};