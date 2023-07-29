#include <bits/stdc++.h>
using namespace std;

int n;
int a[23][23], tmp_route=0, min_to0=0, tmp_start=0, ans=100000, a_state[23];

void Try(int k, int start){
    // cout<<k<<" "<<start<<" "<<tmp_route<<endl;
    for (int i=1;i<=n;i++){
        if (a_state[i]==0){
            // cout<<"try "<<i<<endl;
            if (k==n){
                // cout<<"test"<<endl;
                if (tmp_route+a[start][i]+a[i][i+n]+a[i+n][0]<ans){
                    ans=tmp_route+a[start][i]+a[i][i+n]+a[i+n][0];
                    // cout<<"ans "<<ans<<endl;
                }                
            } else {
                // cout<<"tmp_route "<<tmp_route<<" start "<<start<<endl;
                a_state[i]=1;
                a_state[i+n]=1;
                tmp_route+=a[start][i];
                tmp_route+=a[i][i+n];
                // cout<<"tmp_route check "<<tmp_route<<" "<<a[start][i]<<" "<<a[i][i+n]<<endl;
                // tmp_start=start;
                // start=i+n;
                if (tmp_route+min_to0<ans){
                    Try(k+1, i+n);
                }
                a_state[i]=0;
                a_state[i+n]=0;
                tmp_route-=a[start][i];
                tmp_route-=a[i][i+n];
                // start=tmp_start;
            }
        }
    }
}

int main(){
    cin>>n;
    for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++){
            cin>>a[i][j];
        }
    }
    // cout<<endl;
    // for (int i=0;i<2*n+1;i++){
    //     for (int j=0;j<2*n+1;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i=0;i<23;i++){
        a_state[i]=0;
    }
    min_to0=a[n+1][0];
    for (int i=n+1;i<2*n;i++){
        min_to0=min(min_to0, a[i][0]);
    }
    Try(1, 0);
    cout<<ans;
    return 0;
}