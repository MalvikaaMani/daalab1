class Solution {
public:
   int n, a[305], dp[305][305];
    int solve(int l, int r) {
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for (int i = l + 1; i < r; i++) {
            int sum = solve(l, i) + solve(i, r);
            sum += (a[l] * a[i] * a[r]);
            ans = max(ans, sum);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        for(int i=0; i<n; i++) a[i+1] = nums[i];
        a[0] = 1;
        a[n+1] = 1;
        n++;
        int ans = solve(0, n);
        return ans;
    }
};
