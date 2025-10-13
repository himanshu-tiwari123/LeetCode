class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        map<string,vector<int>>mp;

        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }

        for(auto &v: mp){
            vector<string>res;
             
            for(auto &i: v.second){
                res.push_back(strs[i]);
            }

            ans.push_back(res);
        }


        return ans;
    }
};