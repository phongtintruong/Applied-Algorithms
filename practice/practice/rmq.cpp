// calculate sum rmq
#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int st[1000000][20];

void preprocessing(int n){
    // cout<<"preprocessing"<<endl;
    for (int i=0;i<n;i++){
        st[i][0]=a[i];
    }
    for (int j=1;(1<<j)<=n;j++){
        for (int i=0;i+(1<<j)-1<=n;i++){
            st[i][j]=min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            // cout<<st[i][j]<<" ";
        }
        // cout<<endl;
    }
}

int query(int l, int r){
    int k = log2(r-l+1);
    // cout<<l<<" "<<r<<" "<<k<<endl;
    // cout<<st[l][k]<<" "<<st[r-(1<<k)+1][k]<<endl;
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

// int query(int l, int r) {
//     int len = r - l + 1;
//     int sum = 0;
//     for (int j = 0; (1 << j) <= len; ++j)
//         if (len >> j & 1) {
//             sum = sum + st[l][j];
//             l = l + (1 << j);
//         }
//     return sum;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    preprocessing(n);

    int m, ans=0;
    cin>>m;
    for (int i=0;i<m;i++){
        int l, r;
        cin>>l>>r;
        ans+=query(l, r);
        // cout<<"ans "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}