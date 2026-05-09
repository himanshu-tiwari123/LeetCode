class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>ans;

        //nums[i] + nums[j] = -(nums[k]);

        set<vector<int>>st;

        sort(nums.begin(),nums.end());

        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;

            int c = nums[k];
            

            while(i<j){
                int a = nums[i], b = nums[j];
                
                if(a+b+c == 0){
                    st.insert({nums[i],nums[j],nums[k]});
                    i++;j--;

                }else if( a+b+c < 0){
                    i++;
                }else{
                    j--;
                }
            }
           
        }

        for(auto &it: st){
            ans.push_back(it);
        }


        return ans;
    }
};