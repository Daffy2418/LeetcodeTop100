class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        int q = (int)sqrt(n);
        for (int i = 0; i <= q; i ++) {
            f[i * i] = 1;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j * j <= i; j ++) {
                f[i] = min(f[i], f[i - j * j] + 1); // better solution by using route i-j*j
            }
        }
        return f[n];
    }
};
