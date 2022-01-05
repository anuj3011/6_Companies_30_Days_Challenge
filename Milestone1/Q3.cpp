#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string s;
  char temp;
  int count=1;
  temp=src[0];
  s.push_back(temp);
  for(int i=1;i<src.length();i++){
      if(src[i]==temp){
          count++;
      }
      else{
          temp=src[i];
          s.push_back(count + '0');
          s.push_back(temp);
          count=1;
      }
     
  }
   s.push_back(count + '0');
  return s;
}     
 
