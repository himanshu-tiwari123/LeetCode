class Solution {
public:
    int numSquares(int n) {
        vector<int>perfectSquares;

        for(int i=1;i<=100;i++){
            perfectSquares.push_back(i*i);
        }

        vector<vector<int>>dp(100,vector<int>(n+1,-1));

        auto findAns = [&](auto &self, int index, int n)->int{
            //Base Case:
            if(n==0){
                return 0;
            }
            if(index >= perfectSquares.size()){
                return 1e9;
            }

            if(dp[index][n]!=-1){
                return dp[index][n];
            }

            int not_take = self(self,index+1,n);

            int take = 1e9;

            if(n-perfectSquares[index] >= 0){
                take = 1 + self(self,index, n-perfectSquares[index]);
            }


            return dp[index][n] = min(take,not_take);
        };



        return findAns(findAns,0,n);
    }
};