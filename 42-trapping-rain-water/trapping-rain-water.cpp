class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if (n == 0)
            return 0;

        vector<int> rightMax(n, 0), leftMax(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= height[i])
                st.pop();
            leftMax[i] = st.empty() ? height[i] : st.top();
            if (st.empty())
                st.push(height[i]);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= height[i])
                st.pop();
            rightMax[i] = st.empty() ? height[i] : st.top();

            if (st.empty())
                st.push(height[i]);
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            ans+= min(leftMax[i],rightMax[i])-height[i];
        }

        return (int) ans;
    }
};