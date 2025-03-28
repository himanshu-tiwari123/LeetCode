class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // Function to compute sum of ops(x) from 0 to m
        auto sum_ops = [](long long m) -> long long {
            if (m < 0) return 0; // Base case for l-1 when l=1
            long long total = 0;
            // Find bit length of m (largest k where 2^(k-1) <= m)
            int n = 0;
            long long temp = m;
            while (temp > 0) {
                n++;
                temp >>= 1;
            }
            if (m == 0) n = 1; // Adjust for m=0 case
            else n = max(1, n); // Ensure n >= 1
            
            // For each bit length k up to n-1 (complete ranges)
            for (int k = 1; k < n; k++) {
                long long count = 1LL << (k - 1); // 2^(k-1)
                long long ops = (k + 1) / 2; // ceil(k / 2)
                total += count * ops;
            }
            // Partial range for bit length n
            long long start = 1LL << (n - 1); // 2^(n-1)
            if (start <= m) {
                long long count = m - start + 1;
                long long ops = (n + 1) / 2; // ceil(n / 2)
                total += count * ops;
            }
            return total;
        };
        
        long long result = 0;
        for (auto& query : queries) {
            long long l = query[0];
            long long r = query[1];
            // Sum of ops(x) from l to r = sum_ops(r) - sum_ops(l-1)
            long long sum = sum_ops(r) - sum_ops(l - 1);
            // Number of operations = ceil(sum / 2)
            long long operations = (sum + 1) / 2;
            result += operations;
        }
        
        return result;
    }
};