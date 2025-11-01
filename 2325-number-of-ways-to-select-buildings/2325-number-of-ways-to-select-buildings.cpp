class Solution {
    using ll = long long;
    ll dp[100005][4][3]; 
    // dp[i]-> {index,len_taken,what was taken previously}
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

        if(len==0 || prev==-1){
            take = findAns(index+1,len+1,s[index]-'0',s);
        }else{
            if(s[index] != prev+'0'){
                take = findAns(index+1,len+1,1-prev,s);
            }
        }

        return dp[index][len][prev+1] = take + not_take;
    }
public:
    long long numberOfWays(string s) {
        int n = s.size();
        // dp.resize(n+1,-1);
        string temp="";
        memset(dp,-1,sizeof(dp));
        return findAns(0,0,-1,s);
    }
};