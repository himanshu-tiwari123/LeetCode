class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>res;

        for(int i=0;i<n-2;i++){
            int a = nums[i];
            if(i>0 and nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;

            while(j<k){
                int b = nums[j], c = nums[k];

                if(a + b + c == 0){
                    res.push_back({a,b,c});
                    j++;
                    k--;

                    while(j>0 and j<k and nums[j] == nums[j-1]){
                        j++;
                    }

                    while(k<n-1 and j<k and nums[k] == nums[k+1]){
                        k--;
                    }
                }else if(a+b+c > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }


        return res;
    }
};