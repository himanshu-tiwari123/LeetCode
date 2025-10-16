class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int>ans;

        stack<int>st;

        for(int i=0;i<n;i++){
            if(asteroids[i] > 0 || (st.empty() and asteroids[i] < 0)){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() and (st.top()>0) and st.top()< abs(asteroids[i])){
                    st.pop();
                }

                if(!st.empty() and st.top()>0 and st.top() == abs(asteroids[i])){
                    st.pop();
                    continue;
                    
                }

                if((!st.empty() and st.top() < 0) || (st.empty())){
                    st.push(asteroids[i]);
                    
                }

               
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};