/*
*if word1[i-1]==word2[j-1]:
*c=0
*else:
*c=1
*a[i][j]=min(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]+c)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int j=1; j<=n; j++)
            dp[0][j] = j;
        
        for(int i=1; i<=m; i++) {
            dp[i][0] = i;
            for(int j=1; j<=n; j++) {
                dp[i][j] = dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]) dp[i][j]++;
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i][j]);
            }
        }
        
        return dp[m][n];
    }
};
