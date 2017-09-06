/*
考虑到二叉树的性质，对于任意以i为根节点的二叉树，它的左子树的值一定小于i，
也就是[0, i - 1]区间，而右子树的值一定大于i，也就是[i + 1, n]。
假设左子树有m种排列方式，而右子树有n种，则对于i为根节点的二叉树总的排列方式就是m x n。
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        //dp初始化
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                //如果左子树的个数为j，那么右子树为i - j - 1
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
