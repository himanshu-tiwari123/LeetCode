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

            if(next_val <= n){
                recursion(next_val,n);
            }else{
                break;
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        for(int val=1;val<=9;val++){
            recursion(val,n);
        }
        

        return ans;
    }
};