class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total_sum = accumulate(cardPoints.begin(),cardPoints.end(),0);

        //We need sum of subarry of length k to be maximum, it's same as saying that subarray of length n-k should be minimum;

        int k1 = (n-k);

        int l=0,r=0,curr_sum = 0, min_sum = INT_MAX ;

        while(r<n){
            curr_sum += cardPoints[r];

            if(r-l+1 == k1){
                min_sum = min(min_sum , curr_sum);
                curr_sum -= cardPoints[l];
                l++;
            }

            r++;
        }

        

        return min_sum == INT_MAX ? total_sum : total_sum - min_sum;

    }
};