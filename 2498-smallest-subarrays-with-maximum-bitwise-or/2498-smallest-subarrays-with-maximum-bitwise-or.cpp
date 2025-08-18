class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();

        vector<int>setBits(31,-1);

        vector<int>ans;
        
        for(int i=n-1;i>=0;i--){
            int val =  nums[i];
            int index = i;
            for(int j=0;j<31;j++){
                if(val & (1<<j)){
                    //this bit is set:
                    setBits[j] = i;
                }else{
                    //this bit is not set ,so we need to take help of setBits array:
                    index = max(index,setBits[j]);
                }
            }

            ans.push_back(index-i+1);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};