class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();

        unordered_map<char,int>mp;

        for(int i=0;i<m;i++){
           mp[t[i]]++;
        }

        int index =-1;
        int min_len = INT_MAX;
        
        int l=0,r=0,cnt = 0;

        while(r<n){
            if(mp[s[r]]>0){
                //this character is present in the f1:
                cnt++;
            }
            mp[s[r]]--;

            while(cnt == m){
                //first we need to calculate the length:
                if((r-l+1) < min_len){
                    min_len = r-l+1;
                    index = l;
                }
                //now try to shrink the window:
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt--;
                }

                l++;
            }

            r++;
        }
    

        return (index==-1 ?  "" : s.substr(index,min_len)); 


    }
};