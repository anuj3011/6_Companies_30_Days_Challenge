#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull arr[n];
	    arr[0]=1;
	    ull next_multiple_2=2;
	    ull next_multiple_3=3;
	    ull next_multiple_5=5;
	    ull i2=0,i3=0,i5=0;
	    ull next_ugly=1;
	    for(int i=1;i<n;i++){
	        next_ugly= min(next_multiple_2,min(next_multiple_3,next_multiple_5));
	        arr[i]=next_ugly;
	        if(next_ugly==next_multiple_2){
	            i2++;
	            next_multiple_2=arr[i2]*2;
	        }
	        if(next_ugly==next_multiple_3){
	            i3++;
	            next_multiple_3=arr[i3]*3;
	        }
	        if(next_ugly==next_multiple_5){
	            i5++;
	            next_multiple_5=arr[i5]*5;
	        }
	       // cout<<next_ugly<<endl;
	    }
	    return arr[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends