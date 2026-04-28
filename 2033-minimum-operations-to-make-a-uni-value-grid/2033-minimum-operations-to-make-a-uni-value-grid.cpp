class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size() , m= grid[0].size();

        if(n==1 and m==1){
            return 0;
        }

        vector<int>temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        int mid_val = temp[temp.size()/2];

        cout<<mid_val;

        int ans = 0;

        for(auto &it: temp){
            
            int val = (abs(mid_val - it))%x;

            if(val == 0){
                ans += (abs(mid_val - it))/x;
            }else{
                return -1;
            }
        }

         return ans;


    }
};