class Solution{
public:
    int lengthOfLongestAP(int A[], int n) {
        int ans=0;
        int maxval=0;
        for(int i = 0; i < n ;i++){
            maxval=max(A[i],maxval);
        }
        vector<vector<int>> dp(2*maxval+1,vector<int>(n,0));
        for(int i=1;i<n;++i)
            for(int j=0;j<i;++j)
            {
                int dif=A[i]-A[j]+maxval;
                dp[dif][i]=dp[dif][j]+1;
                ans=max(ans,dp[dif][i]);
            }
        return ans+1;
    }
};