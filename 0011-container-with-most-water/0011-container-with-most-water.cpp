class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n= arr.size();
        
        int l=0,r=n-1;

        int max_ans =  0;

        while(l<=r){
            int curr_ans = (r-l)*min(arr[l],arr[r]);
            if(arr[l]<=arr[r]){
               l++;
            }else{
               r--; 
            }

            max_ans = max(max_ans,curr_ans);
        }


        return max_ans;
    }
};