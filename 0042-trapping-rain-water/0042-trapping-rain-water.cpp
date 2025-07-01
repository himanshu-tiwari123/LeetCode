class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefMax(n),suffMax(n);
        prefMax[0] = height[0],suffMax[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            prefMax[i] = max(prefMax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffMax[i] = max(suffMax[i+1],height[i]);
        }

        //Now the ans at any index is : min(prefMax[i],suffMax[i])-height[i];
        int total_ans = 0;

        for(int i=0;i<n;i++){
           int curr_ans = min(prefMax[i],suffMax[i])-height[i];
           total_ans += curr_ans;
        }


        return total_ans;

    }
};