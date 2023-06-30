#include<iostream>
using namespace std;
int main(){
    unsigned long long a, b, c=1e9 +7, ans=1;
    cin>>a>>b;
    unsigned long long a_mod_c=a%c;
    for (int i=0;i<b;i++){
        ans = (ans*a_mod_c)%c;
    }
    cout<<ans;
    return 0;
}