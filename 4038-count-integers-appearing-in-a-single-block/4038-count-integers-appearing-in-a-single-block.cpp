class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        int i=0,j=0;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        set<int>st;

        while(i<n){
            int val = nums[i];
            
            j=i;

            while(j<n and nums[j] == nums[i]){
                mp[nums[j]]--;
                j++;
            }

            if(mp[nums[i]] == 0){
                if(st.find(val) == st.end()){
                    cnt++;
                }

            }else{
                st.insert(val);
            }

            i=j;
            

        }

        return cnt;
    }
};