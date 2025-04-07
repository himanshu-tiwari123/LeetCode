class Solution {
    vector<int>dp;
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n =  nums.size();
       
        dp.resize(n,1);
        
        int lis = 0;
        for(int index=0;index<n;index++){
            
            for(int j=0;j<index;j++){
                if((nums[index]%nums[j]) == 0 and dp[index] < dp[j]+1){
                    dp[index] = dp[j]+1;
                }
            }

            
            lis = max(lis,dp[index]);
        }

        //Now we need to store those elements in array:
        vector<int>ans;
        int index = n-1;

        while(lis>0){
           if(dp[index]==lis){
               if((ans.empty()) || (ans.back()%nums[index]) == 0){
                    ans.push_back(nums[index]);
                    lis--;
               }
           }

           index--;
        }

        return ans;
    
    }
};