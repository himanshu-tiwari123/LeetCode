class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();

        vector<string>ans;

        unordered_set<string>st;
        int i = 0;
        while(i<n){
            string str;
            str += s[i];
            int j=i+1;
            while(j<n and st.find(str)!=st.end()){
                str += s[j];
                j++;
            }
            if(st.find(str) == st.end()){
                ans.push_back(str);
            }
            
            st.insert(str);
            i = j;
        }


        return ans;
    }
};