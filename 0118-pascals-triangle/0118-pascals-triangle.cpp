class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        vector<int>ans;
        for(int i=0;i<n;i++){
          ans.resize(i+1,1);
          //first and last are 1s so dont touch them 
            for(int j=1;j<i;j++){
              ans[j]=res[i-1][j] + res[i-1][j-1];
            }

            res.push_back(ans);
        }

    return res;
    }
};