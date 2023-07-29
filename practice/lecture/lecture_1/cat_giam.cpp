#include<iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio (0);
    cin . tie (0); cout . tie (0);

    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int a[4];
        for (int i=0;i<4;i++){
            cin>>a[i];
            if (i==0) continue;
            int key=a[i],k=i-1;
            while (k>=0&&key<a[k]){
                a[k+1]=a[k];
                k--;
            }
            a[k+1]=key;
        }
        int ans = a[1]<0?a[0]+a[1]:(a[0]<0?a[0]:0);
        cout<<ans;
        }
    return 0;
}