class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        // vector<int>list1,list2;

        // int cnt = 0;

        // for(auto &it: nums){
        //     if(it < pivot){
        //         list1.push_back(it);
        //     }else if(it == pivot){
        //         cnt++;
        //     }else{
        //         list2.push_back(it);
        //     }
        // }

        

        // int i=0,j=0;

        // while(i<list1.size()){
        //     cout<<i<<" ";
        //     nums[i++] = list1[i];
        
        // }

        // while(cnt > 0){
        //     cout<<i<<" ";
        //     nums[i++] = pivot;
        //     cnt--;
        // }

    
        // while(j<list2.size()){
        //     cout<<i<<" ";
        //    nums[i++] = list2[j++];
        // }

        // return nums

        //Method 2: 3 pointers:
        int less_cnt = 0, equal_cnt  = 0;

        for(auto &it: nums){
            if(it < pivot){
                less_cnt ++;
            }else if(it == pivot){
                equal_cnt ++;
            }
        }

        vector<int>ans(n);

        int i=0, j = less_cnt , k = less_cnt + equal_cnt;

        for(auto &it: nums){
            if(it < pivot){
                ans[i++] = it;
            }else if(it == pivot){
                ans[j++] = it;
            }else{
                ans[k++] = it;
            }
        }
        
        return ans;
    }
};