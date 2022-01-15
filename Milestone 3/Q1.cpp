vector<vector<int>> lookup ;

class Solution{
    public:
    int minDifference(int arr[], int n){
        lookup.clear();
        int sum=0;
        for(int i = 0 ; i < n ; ++i) {
            sum += arr[i];
        }
        lookup.resize(n);
        for(int i=0;i<n;++i){
            lookup[i].assign(sum+1,-1);
        }
        return solve(arr, n - 1, 0, 0);
    }
    int solve(int S[], int n, int S1, int S2)
    {
        // Base case: if the list becomes empty
        if (n < 0) {
            return abs(S1 - S2);
        }
    
        // Construct a unique map key from dynamic elements of the input.
        
        int &ans=lookup[n][S1];
        if(ans != -1)
        return ans;
        int inc = solve(S, n - 1, S1 + S[n], S2);
        int exc = solve(S, n - 1, S1, S2 + S[n]);
        
        ans=min(inc,exc);
        return ans;
        
    }

};