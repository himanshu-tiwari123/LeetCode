class Solution {
    vector<vector<int>>ans;
    void findAns(int index,vector<int>&ds,vector<int>&nums){
        //Base Case:
        if(index>=nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);

        findAns(index+1,ds,nums);

        ds.pop_back();

        while(index+1<nums.size()  and nums[index]==nums[index+1]){
           index++; //this is skippig duplicates as they are close to each other

        }

        findAns(index+1,ds,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        sort(nums.begin(),nums.end());//to help us remove duplicates easily:
        findAns(0,ds,nums);

        return ans;

    }
};