#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio (0);
    cin . tie (0); cout . tie (0);

    string a,b,c="";
    cin>>a;
    cin>>b;
    while (a.length()<b.length()){
        a="0"+a;
    }
    while (a.length()>b.length()){
        b="0"+b;
    }
    int n = a.length(), carry=0;
    for (int i=n-1;i>=0;i--){
        int d = (a[i]-'0')+(b[i]-'0')+carry;
        carry = d/10;
        c=(char)(d%10+'0')+c;
    }
    cout<<(carry?'1'+c:c);
}