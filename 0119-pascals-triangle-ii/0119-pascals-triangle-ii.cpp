#define ll long long
class Solution {
    int calc_nCr(int n,int r){
        double num = 1;

        for(int i=0;i<r;i++){
            num *= (n-i);
            num /= (i+1);
        }

        return num;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        //We need to calculate nC0 , nC1,nC2,.....,nCn
        for(int i=0;i<=(rowIndex)/2;i++){
            int val = calc_nCr(rowIndex,i);
            
            ans.push_back(val);

        }

        for(int i=(rowIndex/2)+1 ; i<=rowIndex;i++){
            ans.push_back(ans[rowIndex-i]);
        }

        return ans;
        
    }
};