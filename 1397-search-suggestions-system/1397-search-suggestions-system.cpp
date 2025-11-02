class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>>ans;

        string s = "";

        for(auto &c :searchWord){
            s +=c;
            int l = s.size();
            vector<string>res;
            for(int i=0;i<n;i++){
               string temp = products[i].substr(0,l);
                if(s == temp){
                    res.push_back(products[i]);
                }
            }

            sort(res.begin(),res.end());
            vector<string>t;
            for(int i=0;i<min(3,(int)res.size()); i++){
               t.push_back(res[i]);
            }

            ans.push_back(t);
        }

        return ans;
    }
};