class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        // 1) Build a "minSuffix" array so that minSuffix[i] = smallest character in s[i..n-1].
        vector<char> minSuffix(n);
        minSuffix[n-1] = s[n-1];
        for (int i = n-2; i >= 0; --i) {
            // take the smaller of s[i] or the suffix-min at i+1
            minSuffix[i] = min(s[i], minSuffix[i+1]);
        }

        string ans;
        ans.reserve(n);
        stack<char> st;     // this represents the robot’s string t
        int i = 0;

        // 2) While there are still characters left in s (i < n) or the stack isn’t empty:
        while (i < n || !st.empty()) {
            // If the stack is nonempty AND (we’ve used up all of s OR top of stack ≤ smallest remaining in s),
            // then pop from stack into ans.
            if (!st.empty() && (i == n || st.top() <= minSuffix[i])) {
                ans.push_back(st.top());
                st.pop();
            } else {
                // Otherwise, we still need to take the next character from s[i] and push it into the stack.
                st.push(s[i]);
                ++i;
            }
        }

        return ans;
    }
};
