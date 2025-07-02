class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    vector<int> getFreq(string word) {
        int count = 1;
        vector<int> ans;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                ans.push_back(count);
                count = 1;
            }
        }
        ans.push_back(count);

        return ans;
    }

    int solve(int i, int count, vector<int>& freq, int k) {

        if (i >= freq.size()) {
            return count < k ? 1 : 0;
        }

        if (dp[i][count] != -1)
            return dp[i][count];

        long long result = 0;

        for (int take = 1; take <= freq[i]; take++) {
            if (count + take < k) {
                result = (result + solve(i + 1, count + take, freq, k)) % MOD;
            } else {
                break;
            }
        }

        return dp[i][count] = result;
    }

public:
    int possibleStringCount(string word, int k) {

        int n = word.size();
        if (k > n)
            return 0;

        vector<int> freq = getFreq(word);
        long long possible = 1;
        for (int& i : freq)
            possible = (possible * i) % MOD;
        if (freq.size() >= k)
            return possible;

        //     dp.assign(freq.size(),vector<int>(k+1,-1));
        // // Need To count invalid strings
        //     long long invalid=solve(0,0,freq,k);

        //     return (possible-invalid+MOD)%MOD;

        dp.assign(freq.size() + 1, vector<int>(k + 1, 0));

        for (int count = k - 1; count >= 0; count--) {
            dp[freq.size()][count] = 1;
        }

        //     for(int i = freq.size()-1; i >= 0; i--) {
        //     for(int count = k-1; count >= 0; count--) {
        //         long long result = 0;

        //         for(int take = 1; take <= freq[i]; take++) {
        //             if(count + take < k) {
        //                 result = (result + dp[i+1][count + take]) % MOD;
        //             } else {
        //                 break;
        //             }
        //         }
        //         dp[i][count] = result;
        //     }
        // }

        for (int i = freq.size()-1; i >= 0; i--) {
            vector<int> prefix(k + 1, 0);

            for (int h = 1; h <= k; h++) {
                prefix[h] = (dp[i + 1][h - 1] + prefix[h - 1]) % MOD;
            }

            for (int count = k - 1; count >= 0; count--) {
                int l = count + 1;
                int r = count + freq[i];
                if(r+1>k) r=k-1;
                if (l <= r)
                    dp[i][count] = (prefix[r + 1] - prefix[l]+MOD)%MOD; // O(1)
            }
        }

        long long invalid = dp[0][0];
        return (possible - invalid + MOD) % MOD;
    }
};