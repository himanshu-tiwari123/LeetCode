class Solution {
public:
    int numTrees(int n) {
        //this can be done using the Catalan Numbers:
        // G(n) = C(2n,n)/(n+1);
        // G(3) = C(6,3)/4 => 20/4 = 5

        //But we can also try to solve it recursively
        //Let G(n) denoted the no of Unique BSTs for nth node.
        //So G(i) -> no of unique BST for the ith node, which can be calculated by G(i-1)*G(n-i). Why multiplication, cause these are independent of each other , the no of way possible for left subtree is independet of no of ways possible for the right subtree

        vector<int>dp(n+1,0);

        dp[0] = 1; // Empty tree bhi ek valid structure hai
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            int ans = 0;

            for(int j=1;j<=i;j++){
                ans += dp[j-1]*dp[i-j];
            }

            dp[i] = ans;
        }

        return dp[n];
    }
};