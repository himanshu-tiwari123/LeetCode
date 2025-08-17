class Solution {
    const int modulo = 1e9+7;
    #define ll long long
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),q = queries.size();

        for(int i=0;i<q;i++){
            int l=queries[i][0],r=queries[i][1],k=queries[i][2],v=queries[i][3];

            while(l<=r and l<nums.size()){
                nums[l] = ((ll)nums[l]*v)%modulo;
                l+=k;
            }
        }

        int xor_ans = 0;

        for(int i=0;i<n;i++){
          xor_ans ^= nums[i];
        }

        return xor_ans;
    }
};