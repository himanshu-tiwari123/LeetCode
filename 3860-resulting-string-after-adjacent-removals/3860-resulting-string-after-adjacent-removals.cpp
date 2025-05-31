class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                int fi = st.top()-'a';
                int se = s[i]-'a';
                if(abs(se-fi)==1 or abs(se-fi)==25){
                    st.pop();
                    continue;
                }
            }

            st.push(s[i]);
        }


        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        } 

        if(ans.empty()){
            return "";
        }  

        reverse(ans.begin(),ans.end());

        return ans;             
    }
};