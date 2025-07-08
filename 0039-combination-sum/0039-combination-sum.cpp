class Solution {
    vector<vector<int>>ans;
    void findAns(int index,vector<int>& candidates,vector<int>&res,int target){
        //Base Case:
        if(target<0 || index>=candidates.size()){
            return;
        }
        if(target == 0){
            ans.push_back(res);
            return;
        }

        findAns(index+1,candidates,res,target);

        if(target-candidates[index] >= 0){
            res.push_back(candidates[index]);
            findAns(index,candidates,res,target-candidates[index]);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        findAns(0,candidates,res,target);
        return ans;
    }
};