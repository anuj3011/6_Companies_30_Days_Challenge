#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    gcd(b,b%a);
}

string gcdOfStrings(string a, string b) {
         return (a + b== b + a)  ? a.substr(0, gcd(a.length(), b.length())): "";
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<gcdOfStrings(a,b);
}
