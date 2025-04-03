class Solution {
    #define ll long long
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftMax(n),rightMax(n);
        leftMax[0]=nums[0],rightMax[n-1]= nums[n-1];

        for(int i=1;i<n-1;i++){
            leftMax[i] = max(leftMax[i-1],nums[i-1]);
            rightMax[n-1-i] = max(rightMax[n-i],nums[n-i]);
        }

        for(auto &it:leftMax){cout<<it<<" ";}cout<<"\n";
        for(auto &it:rightMax){cout<<it<<" ";}

        ll ans = 0;

        for(int i=1;i<n-1;i++){
            ans = max(ans,(ll)(leftMax[i]-nums[i])*rightMax[i]);
        }

        return ans;
    }
};