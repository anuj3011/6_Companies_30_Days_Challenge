//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  void checkAnagrams(vector<string>& string_list,vector<vector<string>> &result){
      int n=string_list.size();
      unordered_map<string,vector<string>> map;
      for(int i=0;i<n;i++){
          string temp=string_list[i];
          sort(temp.begin(),temp.end());
          map[temp].push_back(string_list[i]);
      }
      
      unordered_map<string,bool> check;
      for(int i=0;i<n;i++){
          string temp=string_list[i];
          sort(temp.begin(),temp.end());
          if(!check[temp])
            {
                result.push_back(map[temp]);
                check[temp]=true;
            }
      }
      
  }
  
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> result;
        checkAnagrams(string_list, result);
        return result;
    }
};

// { Driver Code Starts.



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends