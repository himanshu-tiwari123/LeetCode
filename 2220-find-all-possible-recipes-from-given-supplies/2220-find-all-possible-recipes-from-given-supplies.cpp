class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = ingredients.size();

        vector<string>ans;
        
        set<string>st;
        for(auto &it:supplies){
            st.insert(it);
        }
        int lastSize=-1;

        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }

        while((int)(st.size()) > lastSize){
          lastSize = st.size();
          int queueSize = q.size();
          cout<<lastSize<<" "<<queueSize<<"\n";

           while(queueSize-- >0){
            
            int currIndex =q.front();
            q.pop();
            bool isPossible =  true;
            for(auto &it:ingredients[currIndex]){
                if(st.find(it)==st.end()){
                    isPossible = false;
                    break;
                }
            }

            if(isPossible){
                st.insert(recipes[currIndex]);
                ans.push_back(recipes[currIndex]);
            }
            else{
                q.push(currIndex);
            }
            
          }
        }
        

        return ans;
    }
};