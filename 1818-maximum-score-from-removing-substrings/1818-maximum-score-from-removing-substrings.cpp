class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int total_ans = 0;

        

        if(x>=y){
            stack<char>st;
           //we want substring of type->"ab";

           for(int i=0;i<n;i++){
            if(!st.empty() and (s[i]=='b' and st.top()=='a')){
              
                    total_ans += x;
                    st.pop();
              
            }else{
               st.push(s[i]);
            }
            
           }

           string str = "";
           
           while(!st.empty()){
             str += st.top();
             st.pop();
           }

           reverse(str.begin(),str.end());

           for(int i=0;i<str.size();i++){
               if(!st.empty() and (str[i]=='a' and st.top()=='b')){
                  
                    total_ans += y;
                     st.pop();
                  
               }else{
                 st.push(str[i]);
               }

               
           }

        }else{
            stack<char>st;
           //we want substring of type->"ba";

           for(int i=0;i<n;i++){
            if(!st.empty() and (s[i]=='a' and st.top()=='b')){
                total_ans += y;
                st.pop();
               
            }else{
              st.push(s[i]);
            }
            
           }

           string str = "";
           
           while(!st.empty()){
             str += st.top();
             st.pop();
           }

           reverse(str.begin(),str.end());

           for(int i=0;i<str.size();i++){
               if(!st.empty() and (str[i]=='b' and st.top()=='a')){
                  total_ans +=x;
                  st.pop();
               }else{
                  st.push(str[i]);
               }
            }
        }

        return total_ans;

    }
};