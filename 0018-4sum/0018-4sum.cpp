class Solution {
    #define pb push_back
    #define ll long long
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        //We will be HashMap pointers man:
        set<vector<int>>st;
        
        //We will store elemnts between pointers j and k in a hashSet, to
        // prevent dupicate elements ie. i!=j and j!=k and k!=l and l!=i;

        for(int i=0;i<n-2;i++){

            for(int j=i+1;j<n-1;j++){

                unordered_set<int>freq;

                for(int k=j+1;k<n;k++){

                    ll curr_sum =  nums[i]+nums[j];
                    curr_sum += nums[k];

                    ll required_sum = target-curr_sum;

                    // cout<<curr_sum<<" "<<required_sum<<"\n";

                    if(freq.find(required_sum)!=freq.end() and required_sum>=INT_MIN and required_sum<=INT_MAX){
                        vector<int>ans = {nums[i],nums[j],nums[k],(int)required_sum};
                        sort(ans.begin(),ans.end());
                        st.insert(ans);
                    }

                    freq.insert(nums[k]);

                }
            }
        }

        vector<vector<int>>res(st.begin(),st.end());

       return res;
    }
};