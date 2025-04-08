class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;

        int n = nums.size();

        for(auto &it:nums){
            mp[it]++;
        }
        // int operations = 0;
        int index=-1;
        for(int i=0;i<n;i+=3){
            bool candoOperation = false;
            if((i<n) && mp[nums[i]]>=2){
                candoOperation = true;
                // mp[nums[i]]--;
            }else if((i+1 <n) && mp[nums[i+1]]>=2){
                candoOperation = true;
                // mp[nums[i+1]]--;
            }else if((i+2 <n) && mp[nums[i+2]]>=2){
                candoOperation = true;
                // mp[nums[i+2]]--;
            }

            if(candoOperation){
                if(i<n){mp[nums[i]]--;}
                if(i+1<n){mp[nums[i+1]]--;}
                if(i+2<n){mp[nums[i+2]]--;}
                index = i;
            }
        }

        return index!=-1 ? (index/3)+1 : 0;
    }
};