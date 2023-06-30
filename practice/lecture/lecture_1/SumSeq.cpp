#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    unsigned long long a[n], ans=0, c=1e9+7;
    for (int i=0;i<n;i++){
        cin>>a[i];
        ans = (ans+a[i]%c)%c;
    }
    cout<<ans;
}