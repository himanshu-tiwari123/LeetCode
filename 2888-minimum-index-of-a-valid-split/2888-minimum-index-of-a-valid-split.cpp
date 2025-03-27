class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>rmp,lmp;
        int n = nums.size();
        for(auto &it:nums){
            rmp[it]++;
        }

        for(int i=0;i<=n-1;i++){
            int count1 = ++lmp[nums[i]];
            int count2 = --rmp[nums[i]];
            cout<<count1<<" "<<count2<<"\n";
            if((count1 >(i+1)/2) and (count2 > (n-1-i)/2)){
                return i;
            }
        }

        return -1;

    }
};