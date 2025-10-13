class Solution {
    bool areAnagrams(string &s,string &t){
        if(t.size() != s.size()) return false;

        vector<int>f1(26,0);
        for(int i=0;i<s.size();i++){
            f1[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++){
            f1[t[i]-'a']--;
           
        }

        for(int i=0;i<26;i++){
            if(f1[i] != 0) return false;
        }


        return true;
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