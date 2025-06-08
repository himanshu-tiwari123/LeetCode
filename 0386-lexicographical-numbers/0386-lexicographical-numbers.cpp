class Solution {
    vector<int>ans;
    void recursion(int curr_val,int n){
      
        //Base Case:
        if(curr_val > n){
            return;
        }
        ans.push_back(curr_val);

        for(int i=0;i<=9;i++){
            int next_val = curr_val*10+i;

            recursion(next_val,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        for(int start=1;start<=9;start++){
            recursion(start,n);
        }
        
        return ans;
    }
};