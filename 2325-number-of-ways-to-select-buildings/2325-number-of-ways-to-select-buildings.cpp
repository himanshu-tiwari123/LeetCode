class Solution {
    using ll = long long;
    ll dp[100005][4][3]; 
    // dp[i]-> {index,len_taken,what value was taken previously}
    ll findAns(int index,int len,int prev,string &s){
        //Base Case:
    
        if(len==3){
           return 1;
        }

        if(index >= s.size()){
            return 0;
        }

        if(dp[index][len][prev+1]!=-1){
            return dp[index][len][prev+1];
        }

        ll not_take = findAns(index+1,len,prev,s);

        ll take = 0;

        if(prev==-1){
            //iska matlab humne abhi tak koi bhi value nhi liya hai,so
            // we can take whatever is present at index;
            take = findAns(index+1,len+1,s[index]-'0',s);
        }else{
            //we gotta take only if the val at curr index != prev taken val
            if(s[index] != prev+'0'){
                take = findAns(index+1,len+1,1-prev,s);
            }
        }

        return dp[index][len][prev+1] = take + not_take;
    }
public:
    long long numberOfWays(string s) {
        int n = s.size();
        // memset(dp,-1,sizeof(dp));
        // return findAns(0,0,-1,s);

        vector<int>zeroes(n,0),ones(n,0);

        zeroes[0] = (s[0] == '0' ? 1: 0);
        ones[n-1] = (s[n-1] == '1' ? 1 : 0);

        for(int i=1;i<n;i++){
            zeroes[i] = (zeroes[i-1] + (s[i]=='0' ? 1 : 0));
        }

        for(int i=n-2;i>=0;i--){
            ones[i] = (ones[i+1] + (s[i] == '1' ? 1: 0));
        }

        ll ways = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
               //we need no of ones on left and no of ones on right:
               ll left = (i>0 ? i-zeroes[i-1] : 0);
               ll right = (ones[i]);
               ways += (left * right);
            }else{
                ll left = (zeroes[i]);
                ll right = (i<n-1 ? n-i-1-ones[i+1] : 0);

                ways += (left*right);

            }
        }

        return ways;
    }
};