class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;

        stringstream ss(s);

        string word ="";

        while(ss >> word){
            st.push(word);
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans +=" ";
        }
        ans.pop_back();

        return ans;
    }
};