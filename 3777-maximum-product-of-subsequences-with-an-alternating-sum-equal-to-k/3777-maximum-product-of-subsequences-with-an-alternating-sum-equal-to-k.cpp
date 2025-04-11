class Solution {
    using ll = long long;
    // Custom hash function for std::array<ll, 4>
    struct ArrayHash {
        size_t operator()(const array<ll, 4>& arr) const {
            size_t seed = 0;
            for (ll num : arr) {
                seed ^= hash<ll>{}(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    unordered_map<array<ll, 4>, ll, ArrayHash> dp;

    ll findAns(ll index, ll sum, ll product, ll parity, int k, int limit, vector<int>& nums) {
        // Base Case:
        if (index >= nums.size()) {
            if (sum == k && product <= limit && parity != 0) {
                return product;
            }
            return -5000;
        }

        // Cap product at (limit + 1) to reduce state space (but don't skip recursion)
        if (product > limit) {
            product = limit + 1;
        }

        array<ll,4> key = {index, sum, product, parity};
        if (dp.count(key)) {
            return dp[key];
        }

        ll not_take = findAns(index + 1, sum, product, parity, k, limit, nums);
        ll take = -5000;

       
        ll new_product;
        if (nums[index] == 0) {
            new_product = 0;  // Multiplying by 0 => product becomes 0
        } else if (product == 0) {
            new_product = 0;  // 0*something= 0
        } else {
            new_product = product * nums[index];
        }

        if (parity == 0 || parity == 2) {
            take = findAns(index + 1, sum + nums[index], new_product, 1, k, limit, nums);
        } else {
            take = findAns(index + 1, sum - nums[index], new_product, 2, k, limit, nums);
        }

        return dp[key] = max(take, not_take);
    }

public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int curr_sum = accumulate(nums.begin(), nums.end(), 0);
        if (k > curr_sum || k < -curr_sum) {
            return -1;
        }

        dp.clear();
        ll res = findAns(0, 0, 1, 0, k, limit, nums);
        return (res != -5000) ? res : -1;
    }
};