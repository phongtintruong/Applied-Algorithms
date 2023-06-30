#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio (0);
    cin . tie (0); cout . tie (0);

    string a, b, c="";
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        while(a.length()<b.length()){
            a="0"+a;
        }
        while(b.length()<a.length()){
            b="0"+b;
        }
        int len=a.length(), carry=0;
        for (int i=len;i>0;i--){
            int tmp = (a[i]-'0')+(b[i]-'0')+carry;
            carry = tmp/10;
            c=(char)(tmp%10+'0')+c;
        }
    }
}