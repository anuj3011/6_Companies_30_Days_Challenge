#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    vector<vector<int> > dpTable;
    vector<vector<int> > bracket;
    string res="";
public:

    void printMat(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<dpTable[i][j]<<" ";
            cout<<endl;    
        }
    }
    
    void printParenthesis(int i, int j, int n, char& name){
        
        
        if (i == j) {
            res+=name;
            name++;
            return;
        }
        res+="(";
        printParenthesis(i,bracket[i][j],n,name);
        printParenthesis(bracket[i][j]+1,j,n,name);
        res+=")";
    }
    
    string matrixChainOrder(int p[], int n){
        for(int i=0;i<n;i++){
            dpTable.push_back(vector<int>(n,0));
            bracket.push_back(vector<int>(n,0));
        }
        for(int s=2;s<n;s++){
            for(int i=1;i<n-s+1;i++){
                int j = s+i-1;
                    dpTable[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        long tmp = dpTable[i][k]+dpTable[k+1][j];
                        tmp+=p[i-1]*p[k]*p[j];
                        if(tmp<dpTable[i][j]){
                            dpTable[i][j]=tmp;
                            bracket[i][j]=k;
                    }
                }
            }    
        }
        char name = 'A';
        printParenthesis(1,n-1,n,name);
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}