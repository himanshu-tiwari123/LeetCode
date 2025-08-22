class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();

        int best = 0;

        string ans = "";

        for(auto &t: dictionary){
            int m = t.size();

            int l=0,r=0;

            while(l<n and r<m){
                if(s[l] == t[r]){
                    l++;r++;
                }else{
                    l++;
                }
            }

            if(r>=m){
                if(m>best  || (m==best and t<ans)){
                    best = m;

                    ans=t;
                }
            }


        }

        return ans;
    }
};