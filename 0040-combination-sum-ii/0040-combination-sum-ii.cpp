class Solution {
    vector<vector<int>>ans;

    void findAns(int index,vector<int>&temp,int target,vector<int>&arr){
        //Base Case:
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<arr.size();i++){
            if(i != index and arr[i]==arr[i-1]) continue;

            if(target<0) return;

            temp.push_back(arr[i]);

            findAns(i+1,temp,target-arr[i],arr);

            temp.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;

        sort(begin(candidates),end(candidates));

        findAns(0,temp,target,candidates);

        return ans;

    }
};