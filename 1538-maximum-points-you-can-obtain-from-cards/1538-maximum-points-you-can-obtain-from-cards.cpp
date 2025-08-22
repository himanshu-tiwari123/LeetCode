class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int score =0;

        vector<int>prefixSum(k),suffixSum(k);
        prefixSum[0] = cardPoints[0] , suffixSum[k-1]=cardPoints[n-1];

        for(int i=1;i<k;i++){
            prefixSum[i] = prefixSum[i-1] + cardPoints[i]; 
        }

        for(int i=k-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1]+cardPoints[n-k+i];
        }

        score = max(prefixSum[k-1],suffixSum[0]);

        int l = k-2,r=k-1;

        while(l>=0){
            int curr_score = prefixSum[l] + suffixSum[r];
            l--;r--;

            score = max(score,curr_score);
        }

        return score;
    }
};