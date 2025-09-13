class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;

        set<char>st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');

        int vowels = 0,consonants=0;

        for(int i=0;i<s.size();i++){
          mp[s[i]]++;
        }

        for(auto &i: mp){
            if(st.find(i.first)!=st.end()){
                vowels = max(vowels,i.second);
            }else{
                consonants = max(consonants,i.second);
            }
        }


        return vowels + consonants;
    }
};