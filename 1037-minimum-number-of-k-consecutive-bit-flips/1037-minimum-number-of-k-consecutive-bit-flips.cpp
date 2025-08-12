class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flip_cnt = 0, n= nums.size();
        unordered_map<int,bool>mp;

        int res = 0;

        for(int i=0;i<n;i++){
            if(i>=k and mp[i-k]==true){
                flip_cnt--;
            }
        
            if((flip_cnt%2==0 and nums[i]==1) || ((flip_cnt&1) and nums[i]==0 )){
                // continue;
            }else{
                //yahan se window shuru krna chahte hai:
                if(i+k > n){
                    return -1;
                }
                else{
                    flip_cnt++;
                    res++;
                    mp[i] = true;
                }
            }
        }

        return res;
    }
};