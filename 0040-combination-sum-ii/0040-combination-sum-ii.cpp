class Solution {
    vector<vector<int>>ans;

    void findAns(int index,vector<int>&temp,int target,vector<int>&arr){
        //Base Case:
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index>=arr.size()){
            return;
        }
        
        //take:
        if(target-arr[index] >= 0){
            temp.push_back(arr[index]);

            findAns(index+1,temp,target-arr[index],arr);

            temp.pop_back();
        }
        //skip duplicate elements:
        while(index+1<arr.size() and arr[index]==arr[index+1]){
            index++;
        }
        ///not-take
        findAns(index+1,temp,target,arr);

       
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;

        ans.clear();

        sort(begin(candidates),end(candidates));

        findAns(0,temp,target,candidates);

        return ans;

    }
};