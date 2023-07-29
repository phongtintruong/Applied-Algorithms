#include <bits/stdc++.h>
using namespace std;

int k, n, ans=0;
int a[110][110];

void process(int group, int start, int tmp_sum){
    cout<<"test0 "<<group<<" "<<start<<" "<<tmp_sum<<endl;
    if (group==k){
        ans=max(ans, tmp_sum);
        return;
    }

    for (int i=start;i<=n-(k-group);i++){
        tmp_sum+=a[group][i];
        process(group+1, i+1, tmp_sum);
        tmp_sum-=a[group][i];

    }
    return;
}

int main(){
    cin>>k>>n;
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<endl;

    // for (int i=0;i<k;i++){
    //     for (int j=0;j<n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    process(0, 0, 0);
    cout<<ans;
    return 0;
}