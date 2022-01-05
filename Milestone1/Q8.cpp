#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int CountWays(string str){
        if(str[0]=='0')
            return 0;
        if(str.length()==1 )
        return 1;
        vector<int> table(str.length()+1,0);
        table[0]=1;
        table[1]=1;
        int len = str.length();
        int mod = 1000000007;
        for(int i=2;i<=len;i++){
            if(str[i-1]>'0')
                table[i]=table[i-1];
            if(str[i-2]=='1' || str[i-2]=='2' && str[i-1]<'7')
                table[i] = (table[i]+table[i-2])%mod;       
        }
        return table[str.length()];
}
		    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends