/* Dynamic Programming
*         0           if s[i]=='('
*  dp[i]= dp[i-2]+2   if s[i]==')' && s[i-1]=='('
*         dp[i-1]+2+dp[i-dp[i-1]-2]  
            if s[i]==')' && s[i-1]==')' && s[i-dp[i-1]-1]=='('
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),maxLen=0;
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(s[i-1]=='(')
                dp[i]=0;
            if(s[i-1]==')' && s[i-2]=='(')
                dp[i]=dp[i-2]+2;
            if(s[i-1]==')' && s[i-2]==')' && s[i-dp[i-1]-2]=='(')
                dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};
