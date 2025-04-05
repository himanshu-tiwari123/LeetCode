class Solution {
    vector<int>xors;
    void
     findAns(int index,int xor_sum,vector<int>&nums){
        if(index>=nums.size()){
            if(xor_sum!=0){
                xors.push_back(xor_sum);
            }
            return ;
        }
        
        // xors.push_back(xor_sum);

        findAns(index+1,xor_sum,nums);

        findAns(index+1,xor_sum^nums[index],nums);


    }
public:
    int subsetXORSum(vector<int>& nums) {
        findAns(0,0,nums);

        int xor_sum = accumulate(xors.begin(),xors.end(),0);


        return xor_sum;
    }
};