class Solution {
public:
    string clearStars(string s) {
        string ans = "";
        int n = s.size();
        priority_queue<char,vector<char>,greater<char>>pq;

        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans += s[i];
                pq.push(s[i]);
            }else{
                if(!pq.empty()){
                    char smallest = pq.top();
                    pq.pop();
                    int pos = ans.rfind(smallest);
                    if(pos!= string::npos)
                        ans.erase(pos,1);
                }
            }
        }

        return ans;
    }
};