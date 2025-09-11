class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;

        int n = s.size();

        int last_index[26]={0};

        for(int i=0;i<n;i++){
            last_index[s[i]-'a']=i;
        }

        bool visited[26] = {false};

        for(int i=0;i<n;i++){
            char curr = s[i];

            if(visited[curr-'a']) continue; //duplicate element hai bhai:

            while(!st.empty() and curr<st.top() and last_index[st.top()-'a'] > i){
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(curr);
            visited[curr-'a'] = true;

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