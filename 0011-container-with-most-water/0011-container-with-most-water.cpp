class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if(n==2){
            return min(height[0],height[1]);
        }
        int l = 0,r=n-1;

        int max_ans = 0;

        while(l<r){
           int curr_ans = (r-l)*min(height[l],height[r]);

           max_ans = max(max_ans,curr_ans);

            if(height[l] <= height[r]){
              l++;
            }else{
                r--;
            }
        }

        return max_ans;
    }
};