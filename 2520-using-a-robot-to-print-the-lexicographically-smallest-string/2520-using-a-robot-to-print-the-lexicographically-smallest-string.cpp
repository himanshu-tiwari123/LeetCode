class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char>minSuffix(n);
        
        minSuffix[n-1] = s[n-1];
        for(int i=n-2;i>=0;i--){
            minSuffix[i] = min(minSuffix[i+1],s[i]);
        }
        
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
            st.push(s[i]);

            char nextMin = (i+1 < n? minSuffix[i+1] : char('z'));

            while(!st.empty() and st.top() <= nextMin){
                ans += st.top();
                st.pop();
            }
        }


        return ans;

    }
};
