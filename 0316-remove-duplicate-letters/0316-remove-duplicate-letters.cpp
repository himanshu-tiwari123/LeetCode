class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>lastIndex(26,0);
        for(int i=0;i<s.size();i++){
            lastIndex[s[i]-'a']=i;
        }

        stack<char>st;

        vector<bool>inStack(26,false);

        for(int i=0;i<s.size();i++){
            if(inStack[s[i]-'a']) continue;

            while(!st.empty() and st.top() > s[i] and lastIndex[st.top()-'a'] > i){
                inStack[st.top()-'a'] = false;
                st.pop();
            }
            
                inStack[s[i]-'a'] = true;
                st.push(s[i]);
         
          
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};