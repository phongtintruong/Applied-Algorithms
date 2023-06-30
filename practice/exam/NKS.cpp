#include <bits/stdc++.h>
using namespace std;

int n, k, s, ans=0, sum=0;
int a[30], a_state[30];

void Try(int u, int start){
    // cout<<"try "<<sum<<" "<<ans<<" "<<u<<endl;
    for (int i=start;i<n;i++){
        // cout<<"for "<<i<<endl;
        if (sum+a[i]*(k-u+1)>=s&&sum+a[n]*(k-u+1)<=s){
            if (a_state[i]==0){
                if (u==k){
                    if (sum+a[i]==s){
                        // cout<<"correct "<<i<<endl;
                        ans++;
                        // a_state[i]=1;
                    }
                } else {
                    // cout<<i<<endl;
                    a_state[i]=1;
                    sum+=a[i];
                    Try(u+1, i+1);
                    a_state[i]=0;
                    sum-=a[i];
                }
            }
        } else {
            break;
        }
    }
}

int main(){
    cin>>n>>k>>s;
    for (int i=0;i<30;i++){
        a_state[i]=0;
    }
    for (int i=0;i<n;i++){
        cin>>a[i];
        // cout<<a[i]<<endl;
    }
    int size_a = sizeof(a)/sizeof(a[0]);
    sort(a, a+n, greater<int>());
    // for (int i=0;i<n;i++){
    //     cout<<a[i]<<endl;
    // }
    Try(1, 0);
    cout<<ans;
    return 0;
}