class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int>dp(n+1,0);

        // auto findAns =[&](auto &self,int index)->int{
        //     //Base Case:
        //     if(index >=n){
        //         return 1;
        //     }

        //     if(dp[index] != -1){
        //         return dp[index];
        //     }

        //     int one_digit =0 , two_digits = 0;

        //     if(s[index] != '0'){
        //         one_digit = self(self,index+1);
        //     }

        //     if(index+1<n){
        //         int val = ((s[index]-'0')*10 )+ (s[index+1]-'0');

        //         if(val >=10 and val<=26){
        //             two_digits = self(self, index+2);
        //         }


               
        //     }


        //     return dp[index] = one_digit + two_digits;


        // };

        dp[n]  =1 ;

        for(int i=n-1;i>=0;i--){
            int one_digit =0 , two_digits = 0;
            if(s[i] !='0'){
                one_digit = dp[i+1];
            }

            if(i+1 < n){
                int value = ((s[i]-'0')*10)+ (s[i+1]-'0');

                if(value>=10 and value<=26){
                    two_digits = dp[i+2];
                }
            }

            dp[i] = one_digit + two_digits;

            
        }

       return dp[0];

        // return findAns(findAns,0);
    }
};