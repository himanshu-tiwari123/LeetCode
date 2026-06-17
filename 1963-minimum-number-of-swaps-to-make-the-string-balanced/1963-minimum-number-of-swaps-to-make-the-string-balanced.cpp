class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int balance = 0, swaps = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '['){
                balance ++;
            }else{
                balance--;

            }

            if(balance < 0){
                swaps++;
                balance += 2;
            }
        }

        return swaps;
    }
};