class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n  = fruits.size();

      unordered_map<int,int>mp;

      int l = 0,r=0;

      int max_fruits = 0;

      while(r<n){
          
        while(r<n){
          if(mp.size()<2 || mp.find(fruits[r])!=mp.end()){
            mp[fruits[r]]++;
            r++;
          }else{
            break;
          }  
         
        }
        r--;

        int curr_fruits = 0;

        for(auto &it: mp){
          curr_fruits += it.second;
        }

        max_fruits = max(max_fruits,curr_fruits);

        l++;

        int val = fruits[l-1];
        mp[val]--;

        if(mp[val] <= 0){
          mp.erase(val);
        }

        r++;

      }

      return max_fruits;
    }
};