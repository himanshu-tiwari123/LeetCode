class Solution {
    string processString(string &s,int val){
        // reverse(s.begin(),s.end());
        string ans = "";
        // int n = s.size();
        for(int i=1;i<=val;i++){
            ans +=s;
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string curr = "",num="";
                while(!st.empty() and st.top()!='['){
                   curr += st.top();
                   st.pop();
                }
                st.pop();
                //we want a number now which will definitely be below the curr string :
                while(!st.empty() and isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int val = stoi(num);
                string ans = processString(curr,val);
                for(int i=0;i<ans.size();i++){
                    st.push(ans[i]);
                }

            }else{
                st.push(s[i]);
            }
        }
        string str="",number="";
        while(!st.empty()){
            if(!isdigit(st.top())){
                str += st.top();
                

            }else{
                number += st.top();
            }

            st.pop();
           
        }
        if(number.empty()){
            number="1";
        }
        reverse(number.begin(),number.end());

        int value = stoi(number);

        string result = processString(str,value);

        // reverse(result.begin(),result.end());

        return result;

    }
};