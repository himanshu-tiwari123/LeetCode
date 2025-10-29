class Solution {
    vector<int>dp;
    bool findAns(int index,string &s,unordered_set<string>st,vector<string>& wordDict){
        //Base Case:
        if(index >= s.size()){
           return true;
        }

        if(dp[index] != -1 ){
            return dp[index];
        }

        for(int i=index;i<s.size();i++){
            string temp = s.substr(index,i-index+1);

            if(st.find(temp) != st.end() and findAns(i+1,s,st,wordDict)){
                return dp[index] = true;
            }
        }


        return dp[index] = false;

        
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int  n = s.size();

        unordered_set<string>st(wordDict.begin(),wordDict.end());

        dp.assign(n+1,-1);

        return findAns(0,s,st,wordDict);
    }
};