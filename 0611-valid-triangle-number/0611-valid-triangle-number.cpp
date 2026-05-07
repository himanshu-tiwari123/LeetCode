class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int cnt = 0;

        for(int k=n-1;k>=2;k--){
            int c = nums[k];

            int i=0,j=k-1;

            while(i<j){
                int a = nums[i], b=nums[j];

                if(a+b > c){
                    cnt += (j-i);
                    j--;
                }else{
                    i++;
                }
            }
        }

        return cnt;
    }
};