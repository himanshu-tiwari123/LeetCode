class Solution {
    vector<vector<int>>dp;
public:
     
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int  n = nums1.size(),m = nums2.size();

        // dp.assign(n+1,vector<int>(m+1,-1));

        // return findAns(0,0,nums1,nums2);

        dp.assign(n+1,vector<int>(m+1,0));
        //Bottom - up approach:
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        return dp[0][0];


    }
private:
    int findAns(int i,int j,vector<int>&nums1,vector<int>&nums2){
        //Base Case:
        if(i>=nums1.size() or j>=nums2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int connect=0;

        if(nums1[i] == nums2[j]){
            connect = 1 + findAns(i+1,j+1,nums1,nums2);
        }
        
        int not_connect = max(findAns(i+1,j,nums1,nums2),findAns(i,j+1,nums1,nums2));


        return dp[i][j] = max(connect,not_connect);
    }
};