class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // if(n<=2){
        //     return nums;
        // }

        int cnt1=0,cnt2=0,el1=INT_MIN,el2 = INT_MIN;

        for(int i=0;i<n;i++){
            if(cnt1==0 and el2!=nums[i]){
                // cnt1=1;
                el1 = nums[i];
            }
            else if(cnt2==0 and el1!=nums[i]){
                // cnt2=1;
                el2 = nums[i];
            }
            if(nums[i]==el1){
                cnt1++;
            }else if(nums[i] == el2){
                cnt2++;
            }else{
                cnt1--,cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                cnt1++;
            }else if(nums[i]==el2){
                cnt2++;
            }
        }

        if(cnt1 > (n/3) and cnt2>(n/3) and el1!=el2){
            return {el1,el2};
        }

        if(cnt1>n/3 and cnt2<=n/3){
            return {el1};
        }
        if(cnt2>n/3 and cnt1<=n/3){
            return {el2};

        }

        return {};

    }
};