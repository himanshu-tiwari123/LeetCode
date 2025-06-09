class Solution {
#define pb push_back
#define ll long long
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        // We will be HashMap pointers man:
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        // We will store elemnts between pointers j and k in a hashSet, to
        //  prevent dupicate elements ie. i!=j and j!=k and k!=l and l!=i;

        // Now for optimal one we will use a two pointer approach.Here we will
        // use
        //  two loops i and j for traversal and then do the remaining part using
        //  two-pointer approach.Also we try to skip similar elements to avoid
        //  duplicates:

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 and nums[j] == nums[j - 1])
                    continue;

                int k = j + 1, l = n - 1;

                while (k < l) {

                    ll curr_sum = nums[i] + nums[j];
                    curr_sum += nums[k];
                    curr_sum += nums[l];

                    // cout << curr_sum << " ";

                    if (curr_sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(temp);
                        k++;l--;
                        if (k > j + 1) {
                            while (k < l and nums[k] == nums[k - 1]) {
                                k++;
                            }
                        }
                        if (l < n - 1) {
                            while (l > k and nums[l] == nums[l + 1]) {
                                l--;
                            }
                        }

                    } else if (curr_sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return res;
    }
};