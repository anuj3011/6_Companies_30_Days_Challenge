#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    const char list[9] ={'!','#','$','%','&','*','@','^','~'};
	    map<char,bool> map;
	    for(int i=0;i<n;i++){
	        map[nuts[i]]=true;
	    }
	    int i=0;
	    for(auto it: list){
	        if(map[it]) nuts[i++]=it;
	    }
	   // cout<<endl;
	    i=0;
	     for(auto it: list){
	        if(map[it]) bolts[i++]=it;
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends