class Solution {
    #define ll long long
public:
    long long maximumProduct(vector<int>& nums, int m) {
        ll ans = LLONG_MIN;
        int n=nums.size();
        if(m==1){
            for(int i=0;i<n;i++){
                ans = max(ans,(ll)nums[i]*nums[i]);
            }
            return ans;
        }
        vector<int>prefixMax(n-m+1),prefixMin(n-m+1);
        prefixMax[0] = nums[0], prefixMin[0] =nums[0];

        for(int i=1;i<=(n-m);i++){
            prefixMax[i] = max(nums[i],prefixMax[i-1]);
            prefixMin[i] = min(nums[i],prefixMin[i-1]);
        }
        int i =0;
        for(int j=m-1;j<n;j++){
          ll curr_ans=max((ll)prefixMax[i]*nums[j],(ll)prefixMin[i]*nums[j]);
          cout<<curr_ans<<" ";
          ans = max(ans,curr_ans);
          i++;
        }

        return ans;
    }
};