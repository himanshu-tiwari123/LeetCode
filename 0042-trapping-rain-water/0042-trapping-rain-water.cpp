class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();int max_left=0,max_right=0;
        vector<int>prefix_left;vector<int>suffix_right;
     //Creating prefix-left ;
        for(int i=0;i<n;i++){
        max_left=max( max_left,height[i]);
        prefix_left.push_back(max_left);
        }
    //Creating suffix
        for(int i=n-1;i>=0;i--){
        max_right=max( max_right,height[i]);
        suffix_right.push_back(max_right);
        }
       //Reverse the max_right
       reverse(suffix_right.begin(),suffix_right.end());
       //Calculating the amount of water that can be stored
       int  sum=0;

       for(int i=0;i<n;i++){
           int amt_of_water_filled=min(prefix_left[i],suffix_right[i])-height[i];
           sum +=amt_of_water_filled;
       }
       return sum;

    }
};