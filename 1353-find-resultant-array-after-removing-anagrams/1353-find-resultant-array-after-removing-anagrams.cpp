class Solution {
    bool areAnagrams(string &s,string &t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_set<int>indices;
        int n = words.size();
        for(int i=n-1;i>0;i--){
            string s1 = words[i];
            string s2 = words[i-1];

            if(areAnagrams(s1,s2)){
                indices.insert(i);
            }
        }

        vector<string>ans;
        for(int i=0;i<n;i++){
            if(indices.find(i) == indices.end()){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};