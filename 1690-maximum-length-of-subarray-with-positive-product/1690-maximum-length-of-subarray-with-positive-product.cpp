class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0) continue;
            int j=i;
            int neg_cnt = 0;
            int index1 = -1,index2 = -1;
            while(j<n and nums[j]!=0){
                if(nums[j] < 0){
                    neg_cnt++;
                    if(index1==-1){
                        index1= j;
                    }else{
                        index2 = j;
                    }
                }
                j++;
            }

            if(neg_cnt&1){
                if(index2!=-1){
                    max_len = max({max_len,j-index1-1,index2-i});
                }else{
                    max_len = max({max_len,index1-i,j-index1-1});
                }
            }else{
                max_len = max(max_len,j-i);
            }

            i=j;

        }


        return max_len;
    }
};