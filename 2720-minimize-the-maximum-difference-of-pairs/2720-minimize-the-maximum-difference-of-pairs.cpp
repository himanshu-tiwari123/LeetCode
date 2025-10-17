class Solution {
    bool isPossible(int mid,vector<int>&nums,int p){
        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i] <= mid){
                cnt++;
                i++;
            }
        }

        

        return cnt>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();

        if(n==0 || p==0) return 0;
        
        sort(nums.begin(),nums.end());

        int l=0,r=nums[n-1]-nums[0];

        int ans = INT_MAX;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isPossible(mid,nums,p)){
                ans = min(ans,mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
          
        }

       

        return ans;
    }
};