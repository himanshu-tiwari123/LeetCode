class Solution {
    bool isPossible(int d,vector<int>&position,int m){
        int balls=1;
        int n = position.size();
        int curr_dist = position[0];

       for(int i=1;i<n;i++){
        if(position[i] - curr_dist >= d){
            balls++;
            curr_dist = position[i];
        }
       }
        return balls>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low =1,high =position[n-1]-position[0];

        int ans = INT_MIN;

        while(low <= high){
            int mid = (low) + (high-low)/2;

            if(isPossible(mid,position,m)){
               ans = max(ans,mid);
               low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans;
    }
};

