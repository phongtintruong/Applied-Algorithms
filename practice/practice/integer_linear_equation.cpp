#include <iostream>
using namespace std;

int n, m, ans=0, t=0;
int a[100];

void Try(int k){
    // cout<<k<<" "<<n<<" "<<t<<endl;
    int tmp=(m-t-(n-k))/a[k];
    // cout<<"abc"<<endl;
    // cout<<tmp<<endl;
    for (int i=1;i<=tmp;i++){
        if (k==n){
            if ((t+i*a[k])==m){
                ans++;
            }
        } else {
            t+=a[k]*i;
            Try(k+1);
            t-=a[k]*i;
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    Try(1);
    cout<<ans;
    return 0;
}