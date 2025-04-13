class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();

        if (n == 1 or n == 2) {
            return n;
        }

        unordered_set<int> st;

        for(auto &it:nums){st.insert(it);}

        vector<int>arr(st.begin(),st.end());

        unordered_set<int>st1;

        int  m = arr.size();

        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                 st1.insert(arr[j]^arr[k]);
            }
        }

        for(int i=0;i<m;i++){
            for(auto &it:st1){
                st.insert(it^arr[i]);
            }
        }
        return st.size();
    }
};