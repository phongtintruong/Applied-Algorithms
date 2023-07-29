#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int a[100000];

bool check (int distance){
    // cout<<"start "<<distance<<endl;
    int count = 1, i=0, j=1;
    while (i<n){
        while (j<=n&&a[j]-a[i]<distance){
            j++;
        }
        if (j<=n){
            // cout<<a[j]<<endl;
            count++;
        }
        if (count>=c){
            return true;
        }
        i = j;
        j++;
    }
    return false;
}

int max_distance(int l, int r){
    // cout<<"start "<<l<<" "<<r<<endl;
    if (l<r){
        int m=l+(r-l)/2;
        bool isPoss = check(m);
        if (isPoss){
            if (m==l){
                // cout<<m<<endl;
                return m;
            } else {
                return max_distance(m, r);
            }
        } else {
            return max_distance(l, m);
        }
    }
    return -1;
}

int main(){
    // Speed up input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for (int itc=0;itc<t;itc++){
        cin>>n>>c;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n);
        // cout<<"main "<<a[0]<<" "<<a[n-1]<<endl;
        int fr=(a[n-1]-a[0])/(c-1)+1;
        int fl=1;
        
        for (int i=c-1;i<n;i++){
            int tmp = (a[i]-a[i-(c-1)])/(c-1);
            if (tmp>fl){
                fl=tmp;
            }
        }
        // cout<<check(3)<<endl;
        // cout<<tmp<<endl;
        cout<<"start "<<fl<<" "<<fr<<endl;
        cout<<max_distance(fl, fr)<<endl;
    }
    return 0;
}
