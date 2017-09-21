/*
从最小面一层开始往上计算，设dp[i][j]是以第i层j个元素为起点的最小路径和，动态规划方程如下
dp[i][j] = value[i][j] + max{dp[i-1][j], dp[i-1][j+1]}
因为每一层之和它下一层的值有关，因此只需要一个一位数组保存下层的值
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        const int rows = triangle.size();
        int dp[rows];
        for(int i = 0; i < rows; i++)
            dp[i] = triangle[rows-1][i];
        for(int i = rows-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        return dp[0];
    }
};
